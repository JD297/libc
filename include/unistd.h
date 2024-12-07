#include <linux/unistd.h>

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>

#ifndef JD297_LIBC_UNISTD_H
#define JD297_LIBC_UNISTD_H

#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

extern char **environ;

extern long syscall(long number, ...);

extern ssize_t read(unsigned int fd, char *buf, size_t count);

extern ssize_t write(unsigned int fd, const char *buf, size_t count);

extern int close(int fd);

extern pid_t fork(void);

extern int execvpe(const char *file, char *const argv[], char *const envp[]);

extern int execvp(const char *file, char *const argv[]);

extern void _exit(int error_code);

extern char *getcwd(char *buf, size_t size);

extern int chdir(const char *path);

extern int chroot(const char *path);

extern int reboot(int op);
#endif
