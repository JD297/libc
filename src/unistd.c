#include <linux/reboot.h>
#include <arch-x86_64.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>

long syscall(long number, ...)
{
	long ret;

	va_list ap;

	va_start(ap, number);

	switch (number) {
		case __NR_fork:
			ret = SYS_SYSCALL0(number								);
		break;
		case __NR_close:
		case __NR_exit:
		case __NR_uname:
		case __NR_chdir:
		case __NR_chroot:
			ret = SYS_SYSCALL1(number, 	va_arg(ap, long)					);
		break;
		case __NR_munmap:
		case __NR_getcwd:
		case __NR_umount2:
		case __NR_stat:
			ret = SYS_SYSCALL2(number,      va_arg(ap, long), va_arg(ap, long)			);
		break;
		case __NR_read:
		case __NR_write:
		case __NR_open:
			ret = SYS_SYSCALL3(number, 	va_arg(ap, long), va_arg(ap, long), va_arg(ap, long)	);
		break;
		case __NR_mremap:
		case __NR_reboot:
			ret = SYS_SYSCALL4(number,      va_arg(ap, long), va_arg(ap, long), va_arg(ap, long),
							va_arg(ap, long)					);
		break;
		case __NR_mount:
			ret = SYS_SYSCALL5(number,      va_arg(ap, long), va_arg(ap, long), va_arg(ap, long),
							va_arg(ap, long), va_arg(ap, long)			);
		break;
		case __NR_mmap:
			ret = SYS_SYSCALL6(number, 	va_arg(ap, long), va_arg(ap, long), va_arg(ap, long),
							va_arg(ap, long), va_arg(ap, long), va_arg(ap, long)	);
		break;
	}

	va_end(ap);

	return ret;
}

ssize_t read(unsigned int fd, char* buf, size_t count)
{
	long ret;

	if ((ret = syscall(__NR_read, fd, buf, count)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

ssize_t write(unsigned int fd, const char *buf, size_t count)
{
	long ret;

	if ((ret = syscall(__NR_write, fd, buf, count)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int close(int fd)
{
	long ret;

	if ((ret = syscall(__NR_close, fd)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

pid_t fork(void)
{
	long ret;

	if ((ret = syscall(__NR_close)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

void _exit(int error_code)
{
	syscall(__NR_exit, error_code);
}

char *getcwd(char *buf, size_t size)
{
	long ret;

	if ((ret = syscall(__NR_getcwd, buf, size)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int chdir(const char *path)
{
	long ret;

	if ((ret = syscall(__NR_chdir, path)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int chroot(const char *path)
{
	long ret;

	if ((ret = syscall(__NR_chroot, path)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int reboot(int op)
{
	long ret;

	if ((ret = syscall(__NR_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2C, op, NULL)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
