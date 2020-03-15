.. post:: 2012-04-03
   :category: linux
   :author: Jörg Faschingbauer
   :location: Hart bei Graz, Austria
   :language: en

"Why ``ps`` Sucks" or "Counting Memory Consumption"
===================================================

.. sidebar:: Contents

   .. contents::
      :local:

Recently, I held a course on select topics around embedded Linux, at a
company in Zürich. The audience was pretty cool - they had ported
their appliance from a hardcore embedded OS to Linux a couple of years
ago. They are doing quite well nowadays. A bit too much realtime
attitude maybe (``SCHED_RR`` threads all over), but things appear to
work.

On day 1, when we began to dive into multithreading (an inevitable
topic nowadays), an interesting question came up. "We have 70 threads
running, give each thread a stack size of 1 MB, and thus consume 70 MB
for the stacks alone. Add heap and program, and a couple of other
programs. Given a total memory of 128 MB, we're soon dead."

"Can't be!" was my first attempt to clear up the situation. The
attempt was rejected. ``ps`` output sure didn't help a lot either. An
explanation of virtual memory (part of the course anyway) was the
second attempt, but still not bullet proof. More evidence
needed. Fortunately day 1 was over at this point, and I was left with
some overnight homework. During night I was able to come up with a
plausible screenplay in example form, to give a basic understanding of
how Linux does memory management. And that screenplay even backs my
instinctive "Can't be!" defense. It's these late night experiments
that I'm trying to share in this post.

Process Stack Management
------------------------

First off, lets keep out multithreading and examine the stack behavior
of a plain old process. The following program grows the stack up to a
user supplied limit. Normally stack growth is done by calling
functions on top of other functions on top of ... . This is a bit
cumbersome to program when you want to grow the stack up to a given
size, so I use a handy little tricky function, ``alloca``, to allocate
stack space. It does essentially the same - grow stack -, and I don't
have to count stack addresses. Additionally, to be sure that the stack
is actually used ("dirty"), I set the allocated bytes to zero,
explicitly.

.. code-block:: c

   #include <stdio.h>
   #include <unistd.h>
   #include <string.h>
   #include <alloca.h>
   #include <stdlib.h>
   
   static size_t stack_growth; /* stack-allocated bytes */
   
   int main(int argc, char** argv)
   {
       void* mem;
       int error;
       
       if (argc != 2) {
           fprintf(stderr, "%s stack-growth\n", argv[0]);
           exit(1);
       }
   
       stack_growth = atoi(argv[1]);
   
       printf("PID: %d\n", getpid());
   
       mem = alloca(stack_growth);
       memset(mem, 0, stack_growth);
   
       printf("done\n");
       pause();
       return 0;
   }

Compile like so,

.. code-block:: shell

   $ gcc -o process-stack process-stack.c

So, lets start with a small stack,

.. code-block:: shell

   $ ./process-stack 10
   PID: 24299
   done

Examine the various size attributes of the process, using the cool
``-o`` option to ``ps``:

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 24299
      VSZ    SZ  SIZE   RSS
     3944   986   188   320

Ok, that's really small. What do the columns mean? I sure don't know -
``man ps`` is not very exact in its descriptions. Here's my
interpretation.

* ``VSZ`` is the entire "virtual size", whatever this means, in K. We
  sure can't attribute read-only mappings of shared libraries like
  ``glibc`` to the process's memory consumption - ``glibc``'s code is
  shared between all processes that use it, and is resident in memory
  *only once for all processes*. Virtual memory basic usage, so to
  say. The VSZ column tells us nothing about memory usage, I
  presume.
* ``SZ`` is the size of the "core image" of the process, in
  pages. Whatever that is. ``man ps`` tells me something about code,
  stack, data. The page size on my system is 4K, which leads me to
  assume that ``SZ`` roughly equals ``VSZ``. I'm not interested in
  code, so forget about this one either.
* ``SIZE`` looks promising, from what ``man ps`` tells me. "Amount of
  swap that would be required if the process were to dirty all
  writable pages and then be swapped out". Allocated stack is dirtied
  by definition, so this appears to be a good measure of stack
  consumption - at least for our little stack-eater program. I assume
  that the size unit is 1K because ``SIZE`` is a little less than
  ``RSS`` (described below).
* ``RSS``, "Resident set size", in 1K units. This is the amount of
  *non-swapped* memory the process is currently using. This does
  include in-core code pages as well, so this value is of limited
  use. Furthermore, I consider *swapped* memory relevant as well, and
  ``RSS`` doesn't count that.

**Conclusion:** according to the ``SIZE`` column, allocating 10 bytes
on the stack leads me to a program that consumes 188K of main
memory. I suspect that this is the size of a minimal program anyway,
even if it does not consume anything.

Anyway, let's proceed with our tests and eat a million bytes stack.

.. code-block:: shell

   $ ./process-stack 1000000
   PID: 24908
   done

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 24908
      VSZ    SZ  SIZE   RSS
     4800  1200  1044  1376

Ok, the columns have grown within reason and reflect what we
did. Next, we become a bit greedy and want ten million bytes

.. code-block:: shell

   $ ./process-stack 10000000
   PID: 24960
   Segmentation fault

We've hit the stack size limit 8MB which places a barrier against
greedy people,

.. code-block:: shell

   $ ulimit -s
   8192

Eight million bytes is ok, and ``ps`` gives no surprise.

.. code-block:: shell

   $ ./process-stack 8000000
   PID: 25018
   done

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 25018
      VSZ    SZ  SIZE   RSS
    11632  2908  7876  8236

Conclusion
..........

The stack of a process starts small and grows on demand, magically, up
to a limit. The logic is built in to the OS, which makes sense because
it does not make sense to have a process without a stack. The
operating system takes care of extending the stack by allocating
memory under the hood, and we don't want to bother.

Thread (``pthread``) Stack Management
-------------------------------------

Now for thread stacks. The story is a bit different here - POSIX
threads have an attribute "stack size". It can be explicitly set using
``pthread_attr_setstacksize()``, or left default which is 2MB or the
value of the ``RLIMIT_STACK`` resource limit if that is set (see ``man
pthread_create``). A test program similar to the one above, but with
threads instead, would thus have the following parameters:

* ``nthreads``, the number of threads to create
* ``stack-limit``, the *stack size* attribute of each thread. We call
  it "limit" and not "size" as it will turn out that it is exactly
  that.
* ``stack-growth``, the number of bytes to allocate on the stack. This
  is done using ``alloca()``, just like the process test program
  does.

The program creates ``nthreads`` threads. Each thread acts like the
process example program above - allocate stack using ``alloca()`` and
then shut up and sit. It looks as follows.

.. code-block:: c

   #include <pthread.h>
   #include <stdlib.h>
   #include <stdio.h>
   #include <unistd.h>
   #include <string.h>
   
   static size_t nthreads;
   static size_t stack_limit;
   static size_t stack_growth; /* stack-allocated bytes */
   
   static void* thread_func(void* arg)
   {
       void* mem = alloca(stack_growth);
       memset(mem, 0, stack_growth);
       pause();
   }
   
   int main(int argc, char** argv)
   {
       int i;
       pthread_attr_t attr;
       
       if (argc != 4) {
           fprintf(stderr, "%s nthreads stack-limit stack-growth\n", argv[0]);
           exit(1);
       }
   
       nthreads = atoi(argv[1]);
       stack_limit = atoi(argv[2]);
       stack_growth = atoi(argv[3]);
   
       printf("PID: %d\n", getpid());
   
       pthread_attr_init(&attr);
       if (stack_limit > 0) {
           int error = pthread_attr_setstacksize(&attr, stack_limit);
           if (error) {
               fprintf(stderr, "set stack size to %ld: %s (%d)\n",
                               stack_limit, strerror(error), error);
               exit(1);
           }
       }
   
       pthread_attr_t* p_attr = NULL;
       if (stack_limit > 0)
           p_attr = &attr;
   
       for (i=0; i&lt;nthreads; i++) {
           pthread_t id;
           int rv = pthread_create(&id, p_attr, thread_func, NULL);
           if (rv != 0) {
               fprintf(stderr, "failed after %d threads\n", i);
               exit(1);
           }
       }
       
       pause();
       return 0;
   }

Compile like so,

.. code-block:: shell

   $ gcc -pthread -o thread-stack thread-stack.c

Experiment #1: 100 default threads, eating no stack
...................................................

Let's create a hundred threads with default stack size, each eating
100 bytes of stack.

.. code-block:: shell

   $ ./thread-stack 100 0 100
   PID: 31524

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 31524
      VSZ    SZ  SIZE   RSS
   825840 206460 819936 1404

So what? ``SIZE`` reports the process as consuming over 800MB of
memory. According to ``ps``'s description, "if it were to dirty all
writeable pages", then this would be the amount of swap required. A
little calculation shows that ``SIZE`` is approximately 100 times
8MB. 8MB is the ``RLIMIT_STACK`` resource limit that is configured on
my machine (check with ``ulimit -s``), and we started 100 threads. So
it appears that the process has allocated **800MB worth of physical
memory pages, although only 100 bytes of each stack have been eaten**.

"Can't be!" is what I said.

Of course the ``RSS`` field reports much less - but ``RSS`` does not
report swapped memory, so we cannot count on it very much.

But anyway - let's accept the alleged waste of memory for a moment and
carry on with the experiments.

Experiment #2: 100 default threads, eating up stack
...................................................

The first experiment created 100 threads with default stack size 8MB,
and consumed almost nothing of the stacks. Lets eat up the stacks and
see what ``ps`` reports this time.

.. code-block:: shell

   $ ./thread-stack 100 0 8000000
   PID: 771

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 771
      VSZ    SZ  SIZE   RSS
   825840 206460 819936 766604

Aha. ``SIZE`` hasn't changed, but ``RSS`` reports much more than the
last time around. Apparently ``RSS`` does have value - at least on my
system where no swap is configured.

Experiment #3: 100 threads with limited stack
.............................................

See what effect a stack limit has.

.. code-block:: shell

   $ ./thread-stack 100 4096 10
   PID: 1026
   set stack size to 4096: Invalid argument (22)

Ok, we cannot limit the stack to only a single page. We don't insist
(``PTHREAD_STACK_MIN`` is 4 pages anyway), so lets increase stack size
and see what ``ps`` tells us.

.. code-block:: shell

   $ ./thread-stack 100 16384 10
   PID: 1125

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 1125
      VSZ    SZ  SIZE   RSS
     7840  1960  1936  1404

Well. 100 minimal threads lead to a process that consumes minimal
resources. Fine.

**Conclusion:** Provided that we carefully limit our threads' stacks,
we don't eat up too much memory.

Can't be! Do I really have to fine-tune my stacks and risk stack
overflows and hard to find bugs?

Experiment #4: more threads than my system could take (eat no stack)
....................................................................

Now a definitive take: I have 64 bit address space, 4G of physical
RAM, and no swap configured. So, I could create no more than 512
threads with 8MB stack size each - 512*8MB == 4G. Let's try that out
and create 513 threads. Each of the threads eats only 10 bytes of its
stack.

.. code-block:: shell

   $ ./thread-stack 513 0 10
   PID: 2212

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 2212
      VSZ    SZ  SIZE   RSS
   4210920 1052730 4205016 4576

Works! ``ps`` reports more ``SIZE`` than my system can take. What did
they say about ``SIZE``, "*if it were to dirty all writeable pages*"?
This suggests that pages totalling 4205016 bytes have been allocated
to the process. I don't have that many pages, so it seems like I
misunderstand. ``RSS`` seems to be definitive about the size.

Experiment #5: more threads than my system could take (eat stack)
.................................................................

Obviously the system permits its processes to "overcommit"
memory. Others still get their share. Nobody complained during
experiment #4, music kept playing without noticeable stutter. Now lets
actually use the stack.

.. code-block:: shell

   $ ./thread-stack 513 0 8000000
   PID: 4353
   Killed

Ok, that's what I'd expect. Until the process was killed, the Red Hot
Chili Peppers had become overly funky (autio glitches all over), and
the Adobe Flash Plugin had crashed (Good Riddance). Less threads ...

.. code-block:: shell

   $ ./thread-stack 400 0 8000000
   PID: 8462

.. code-block:: shell

   $ ps -o vsz,sz,size,rss -p 8462
      VSZ    SZ  SIZE   RSS
   3284640 821160 3278736 3064580

It looks like I can create a bit more than 400 threads which eat up
their 8MB stacks. Not bad, as these numbers lie well within the
physical constraints of my machine.

So, when I am able to create 400 threads which eat up their 8MB
(default) stacks, then I should be able to create about 800 threads
which eat up half of their 8MB stacks, right?

.. code-block:: shell

   $ ./thread-stack 800 0 4000000
   PID: 11338

That was ok, try 900 threads ...

.. code-block:: shell

   $ ./thread-stack 900 0 4000000
   PID: 12156
   Killed

**Conclusion: We don't have to fine-tune stacks!** Just as with the
process example, thread stacks are allocated *on demand*, up to a
limit. A valid reason to decrease the stack size limit to a lower
value than the default is to keep it from eating up more memory than
expected. Stacks don't shrink, so if I inadvertently - only once -
call a function that uses a 3MB automatic variable, I have a memory
leak.

How does this work?
-------------------

First, have a look at the way the Pthread library sets up a
thread. This is best done with ``strace``. The system call to watch
out for is ``clone()``. ``clone()`` is used to create both processes
(``fork()`` is implemented in terms of ``clone()``) and threads, just
with different kinds of flags.

.. code-block:: shell

   $ strace -f ./thread-stack 30 0 10

The output is rather long, I have tried to keep out the noise and show
only the interesting stuff. We have told the program to create 30
threads with default stack size 8MB. Hence we see 30 blocks like this
one,

.. code-block:: shell

   [pid 14386] clone(child_stack=0x7f5813f22ff0,
             flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHA...) = 14413
   [pid 14386] mmap(NULL, 8392704, PROT_READ|PROT_WRITE, 
             MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7fd14f9af000
   [pid 14386] mprotect(0x7fd14f1ae000, 4096, PROT_NONE) = 0
   [pid 14413] pause( &lt;unfinished ...

What we see here is,

* The main thread, 14386, creates a thread 14413 using ``clone()``
  with the ``CLONE_VM`` flag and a few other flags. The kernel creates
  a new "process" which shares the parent's address space - which is
  basically the definition of a thread.
* The main thread allocates the requested stack using ``mmap()``. This
  creates a *memory mapping* - only a placeholder for memory, to be
  allocated with pages *on demand*, as memory is accessed. The memory
  is accessible in the caller's address space at address
  0x7fd14f9af000, extending for 8392704 bytes. **Note** that this is
  4096 bytes more than the 8MB stack size.
* The main thread protects 4096 bytes at the top of the stack (which
  it has allocated in addition to what was requested) with
  ``PROT_NONE``. Meaning that access to this part of the mapping will
  lead to a segmentation fault. This is cheap and easy stack overflow
  protection.
* The created thread 14413 then calls ``pause()``, which is what the
  threads in our test program do after they have eaten their stack.

Once mappings have been created, we can inspect them in the process's
directory in the ``/proc`` filesystem:

.. code-block:: shell

   $ cat /proc/14386/maps
   ...
   7fd14f1af000-7fd14f9af000 rw-p 00000000 00:00 0 
   7fd14f9af000-7fd14f9b0000 ---p 00000000 00:00 0 
   ...

These two lines are the result of ``mmap (PROT_READ|PROT_WRITE)``,
followed by ``mprotect (PROT_NONE)`` of the topmost page. The first
line is the 8MB stack which has read/write access, the second line is
the "red" stack overflow protection page, without any access bits
set. Still this doesn't show any details of the mapping; these can be
seen from another pseudo-file in the process's ``/proc`` directory. (I
can imagine that the presence of a second file with redundant
information has historical reasons.)

.. code-block:: shell

   $ cat /proc/14386/smaps
   ...
   7fd14f1ae000-7fd14f1af000 ---p 00000000 00:00 0 
   Size:                  4 kB
   Rss:                   0 kB
   Pss:                   0 kB
   Shared_Clean:          0 kB
   Shared_Dirty:          0 kB
   Private_Clean:         0 kB
   Private_Dirty:         0 kB
   Referenced:            0 kB
   Anonymous:             0 kB
   AnonHugePages:         0 kB
   Swap:                  0 kB
   KernelPageSize:        4 kB
   MMUPageSize:           4 kB
   Locked:                0 kB
   7fd14f1af000-7fd14f9af000 rw-p 00000000 00:00 0 
   Size:               8192 kB
   Rss:                   8 kB
   Pss:                   8 kB
   Shared_Clean:          0 kB
   Shared_Dirty:          0 kB
   Private_Clean:         0 kB
   Private_Dirty:         8 kB
   Referenced:            8 kB
   Anonymous:             8 kB
   AnonHugePages:         0 kB
   Swap:                  0 kB
   KernelPageSize:        4 kB
   MMUPageSize:           4 kB
   Locked:                0 kB
   ...

Here we see the same two mappings, but with additional information. It
is exactly this information that we are missing from ``ps``.

The first mapping represents the red page. Its size is 4K. No ``RSS``,
no nothing else. Pretty shallow, not backed by any physical memory.

The second mapping is the stack itself, with the following
information:

* The mapping's extent (Size) is 8MB which is no surprise.
* 8K is currently resident. Again, ``RSS`` does not help much as the
  number is swamped by swap.
* The most important information is ``Private_Dirty`` - the number of
  bytes that are "dirty" and thus have to be allocated and attributed
  to the process. "Private" means that the memory is not shared with
  any other process (stacks are not shared of course), and thus the
  memory is attributed *only to the process*. Here we can see that,
  although the size of the mapping is 8MB, **only 8K are actually
  used**. As it happens the same amount is also resident, but again,
  this need not be.

Conclusion
----------

There's no reason to panic when ``ps`` reports large numbers. It's
just not easy to find out how much memory a process actually
consumes. By understanding the information the ``/proc`` filesystem
provides, you at least have the chance to find out what you need.

What is most important to understand is the *on demand* nature of
memory allocation. That the *size* of a memory mapping is definitely
meaningless, and that mappings are "filled" with memory pages as
memory is actually accessed. Stacks are actually nothing but mappings
as we saw above. The same principle applies to the heap
(``/proc/PID/maps`` and ``/proc/PID/smaps`` actually report a mapping
named "heap"), program code (a mapping which is shared between many
processes and which is read-only), global read-only and read-write
data (the latter is copied on-demand and only then attributed to the
modifying process). There are many other usages of memory mappings -
dig through the ``/proc`` filesystem to find
out. ``Documentation/filesystems/proc.txt`` from the Linux kernel
source code gives a thorough explanation of the ``smaps`` entries, and
much more.

Realtime is different
.....................

*On demand* memory allocation is counter productive in a realtime
scenario as it can delay execution substantially. To overcome this
situation, one needs to make sure memory is actually available
beforehand. No way *having to wait* for stack memory to become
available, for example.

This is what the ``mlock()`` and ``mlockall()`` system calls are there
for - make sure that memory is available when it is needed. When
*locked into memory*, mappings actually become populated with physical
memory. Thread stacks, for example, are physically eaten up as they
are created. Yes, realtime often brings contradictory requirements -
this is one. In such a scenario, as only one example, it does
absolutely make sense to pre-allocate limited stacks for each thread.

But as always, you decide based upon what you know and, most of all,
upon your feeling. I wrote this rather lengthy post because I felt so
lucky that my feeling was right. "Can't be!". It cannot be that an OS
can be so stupid and eat up memory for nothing. I didn't know 100%
sure, so I could have been wrong just as well. If you have read up to
this point at the end of kilometers of characters, then I hope you
agree with me about my conclusions. If not, please comment! One can
never be 100% sure, and I'd be glad to learn.
