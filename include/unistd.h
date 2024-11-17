#include <types.h>

#ifndef JD297_LIBC_UNISTD_H
#define JD297_LIBC_UNISTD_H

#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

#define SYSCALL_READ	0
#define SYSCALL_WRITE	1
#define SYSCALL_EXIT	60

extern ssize_t read(unsigned int fd, char *buf, size_t count);

extern ssize_t write(unsigned int fd, const char *buf, size_t count);

extern void _exit(int error_code);
#endif
