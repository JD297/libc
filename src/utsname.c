#include <errno.h>
#include <unistd.h>

int uname(struct utsname *buf)
{
	long ret;

	if ((ret = syscall(__NR_uname, buf)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
