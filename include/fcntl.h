#ifndef JD297_LIBC_FCNTL_H
#define JD297_LIBC_FCNTL_H

typedef unsigned int mode_t;

extern int open(const char *filename, int flags, ...);
#endif
