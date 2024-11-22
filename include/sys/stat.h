#include <sys/types.h>

#ifndef JD297_LIBC_SYS_STAT_H
#define JD297_LIBC_SYS_STAT_H

typedef struct stat {
	dev_t     st_dev;
	ino_t     st_ino;
	mode_t    st_mode;
	nlink_t   st_nlink;
	uid_t     st_uid;
	gid_t     st_gid;
	dev_t     st_rdev;
	off_t     st_size;
	blksize_t st_blksize;
	blkcnt_t  st_blocks;
	time_t    st_atime;
	time_t    st_mtime;
	time_t    st_ctime;
} stat;

extern int stat(const char *restrict pathname, struct stat *restrict statbuf);

#endif
