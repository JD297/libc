#include <fcntl.h>

int open(const char *filename, int flags)
{
        int ret;

        asm volatile
        (
                "syscall"
                : "=a"(ret)
                : "0"(SYSCALL_OPEN), "D"(filename), "S"(flags), "d"(0)
        );

        return ret;
}
