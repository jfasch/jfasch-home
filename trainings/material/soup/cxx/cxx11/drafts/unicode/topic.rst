(Incomplete) Unicode in C++
===========================

* `A Crash Course in Unicode for C++ Developers - Steve Downey -
  [CppNow 2021] <https://youtu.be/iQWtiYNK3kQ?si=RRdAdjHP4s8P6MJf>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/iQWtiYNK3kQ?si=sZZZytPHV0PgxLYN" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>

  * Best text handling is not to
  * ``std::u8string`` is not Python ``str``

  * ``utf-16``: originally they though 16 bits would be enough for
    everyone (someone also said 640K would be enough)
  * still used as internal Windows and Java representation
  * ``utf-32`` never used, but often used internally to represent code
    points

  * Normalization: comparing two texts that are the same but under a
    different representation

    Bad: there is one code point to represent "Ä", but it can alos be
    represented by "A" and one "modifier" that puts two points over
    preceding character.

* `Applying the Lessons of std::ranges to Unicode in the C++ Standard
  Library - Zach Laine CppNow 2023
  <https://youtu.be/AoLl_ZZqyOk?si=OnWCf-aGPGJvDXeC>`__

  .. raw:: html

     <iframe width="560" height="315" 
             src="https://www.youtube.com/embed/AoLl_ZZqyOk?si=OnWCf-aGPGJvDXeC" 
	     title="YouTube video player" 
	     frameborder="0" 
	     allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
	     referrerpolicy="strict-origin-when-cross-origin" 
	     allowfullscreen>
     </iframe>
