#include <errno.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/utsname.h>

int uname(struct utsname *buf)
{
	long ret;

	if ((ret = syscall(SYS_utsname, buf)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
