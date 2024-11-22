#include <sys/types.h>
#include <types.h>

#ifndef JD297_LIBC_UNISTD_H
#define JD297_LIBC_UNISTD_H

#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

extern long syscall(long number, ...);

extern ssize_t read(unsigned int fd, char *buf, size_t count);

extern ssize_t write(unsigned int fd, const char *buf, size_t count);

extern int  close(int fd);

extern pid_t fork(void);

extern void _exit(int error_code);

extern char *getcwd(char *buf, size_t size);
#endif
