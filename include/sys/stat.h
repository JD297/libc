#include <linux/stat.h>
#include <sys/types.h>

#ifndef JD297_LIBC_SYS_STAT_H
#define JD297_LIBC_SYS_STAT_H

struct timespec {
	__s64	tv_sec;
	__u32	tv_nsec;
	__s32	__reserved;
};

typedef struct stat {
	dev_t		st_dev;
	ino_t		st_ino;
	mode_t		st_mode;
	nlink_t		st_nlink;
	uid_t		st_uid;
	gid_t		st_gid;
	dev_t		st_rdev;
	off_t		st_size;
	blksize_t	st_blksize;
	blkcnt_t	st_blocks;

	struct timespec	st_atime;
	struct timespec st_mtime;
	struct timespec	st_ctime;

	#define st_atime st_atim.tv_sec
	#define st_mtime st_mtim.tv_sec
	#define st_ctime st_ctim.tv_sec
};

extern int stat(const char *restrict pathname, struct stat *restrict statbuf);

#endif
