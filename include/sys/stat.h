#include <sys/types.h>

#ifndef JD297_LIBC_SYS_STAT_H
#define JD297_LIBC_SYS_STAT_H

/* File types. */
#define S_IFMT		0170000	/* These bits determine file type. */

#define S_IFDIR		0040000	/* Directory. */
#define S_IFCHR		0020000	/* Character device. */
#define S_IFBLK		0060000	/* Block device. */
#define S_IFREG		0100000	/* Regular file. */
#define S_IFIFO		0010000	/* FIFO.  */
#define S_IFLNK		0120000	/* Symbolic link. */
#define S_IFSOCK	0140000	/* Socket. */

/* Protection bits. */

#define S_ISUID		04000	/* Set user ID on execution. */
#define S_ISGID		02000	/* Set group ID on execution. */
#define S_ISVTX		01000	/* Save swapped text after use (sticky). */
#define S_IREAD		0400	/* Read by owner. */
#define S_IWRITE	0200	/* Write by owner. */
#define S_IEXEC		0100	/* Execute by owner. */

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
