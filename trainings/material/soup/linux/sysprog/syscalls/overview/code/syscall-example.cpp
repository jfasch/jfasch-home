#include <unistd.h>
#include <sys/syscall.h>                               // <-- SYS_* macros

int main()
{
    pid_t tid = syscall(SYS_gettid);
    (void)tid; // ... or do something with it
    return 0;
}
