#include <sys/types.h>

#ifndef JD297_LIBC_FCNTL_H
#define JD297_LIBC_FCNTL_H

#define O_ACCMODE	0003
#define O_RDONLY	00
#define O_WRONLY	01
#define O_RDWR		02
#define O_CREAT		0100	/* Not fcntl. */
#define O_EXCL		0200	/* Not fcntl. */
#define O_NOCTTY	0400	/* Not fcntl. */
#define O_TRUNC		01000	/* Not fcntl. */
#define O_APPEND	02000
#define O_NONBLOCK	04000
#define O_NDELAY	O_NONBLOCK
#define O_SYNC		04010000
#define O_FSYNC		O_SYNC
#define O_ASYNC		020000

extern int open(const char *filename, int flags, ...);
#endif
