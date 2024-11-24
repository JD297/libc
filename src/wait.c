#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t wait(int *wstatus)
{
	long ret;

	if ((ret = syscall(__NR_wait4, -1, wstatus, 0, NULL)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

