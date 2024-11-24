#include <errno.h>
#include <linux/fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *restrict pathname, struct stat *restrict statbuf)
{
	long ret;

	struct statx statxbuf;

	if ((ret = syscall(__NR_statx, AT_FDCWD, pathname, AT_NO_AUTOMOUNT, STATX_BASIC_STATS, &statxbuf)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	statbuf->st_size = statxbuf.stx_size;
	statbuf->st_mode = statxbuf.stx_mode;

	return ret;
}
