#include <types.h>

#ifndef JD297_LIBC_FCNTL_H
#define JD297_LIBC_FCNTL_H

#define SYSCALL_OPEN	2

extern int open(const char *filename, int flags);
#endif
