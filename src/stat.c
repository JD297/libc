#include <errno.h>
#include <unistd.h>

int stat(const char *restrict pathname, struct stat *restrict statbuf)
{
	long ret;

	if ((ret = syscall(__NR_stat, pathname, statbuf)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
