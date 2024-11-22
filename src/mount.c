#include <errno.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/syscall.h>

int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)
{
	long ret;

	if ((ret = syscall(SYS_mount, source, target, filesystemtype, mountflags, data)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int umount2(const char *target, int flags)
{
	long ret;

	if ((ret = syscall(SYS_umount, target, flags)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
