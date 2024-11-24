#include <linux/types.h>

#ifndef JD297_LIBC_SYS_TYPES_H
#define JD297_LIBC_SYS_TYPES_H

typedef __kernel_ssize_t	ssize_t;
typedef __u16			mode_t;
typedef __kernel_pid_t		pid_t;
typedef __u32			uid_t;
typedef __u32			gid_t;
typedef __u32			id_t;
typedef __u32			dev_t;
typedef __u64			ino_t;
typedef __u32			nlink_t;
typedef __kernel_off_t		off_t;
typedef __u32			blksize_t;
typedef __u64			blkcnt_t;

#endif
