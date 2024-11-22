#include <arch-x86_64.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/syscall.h>

long syscall(long number, ...)
{
	long ret;

	va_list ap;

	va_start(ap, number);

	switch (number) {
		case SYS_fork:
			ret = SYS_SYSCALL0(number								);
		break;
		case SYS_close:
		case SYS_exit:
		case SYS_utsname:
			ret = SYS_SYSCALL1(number, 	va_arg(ap, long)					);
		break;
		case SYS_munmap:
		case SYS_getcwd:
			ret = SYS_SYSCALL2(number,      va_arg(ap, long), va_arg(ap, long)			);
		break;
		case SYS_read:
		case SYS_write:
			ret = SYS_SYSCALL3(number, 	va_arg(ap, long), va_arg(ap, long), va_arg(ap, long)	);
		break;
		case SYS_mremap:
			ret = SYS_SYSCALL4(number,      va_arg(ap, long), va_arg(ap, long), va_arg(ap, long),
							va_arg(ap, long)					);
		break;
		case SYS_mmap:
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

	if ((ret = syscall(SYS_read, fd, buf, count)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

ssize_t write(unsigned int fd, const char *buf, size_t count)
{
	long ret;

	if ((ret = syscall(SYS_write, fd, buf, count)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int close(int fd)
{
	long ret;

	if ((ret = syscall(SYS_close, fd)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

pid_t fork(void)
{
	long ret;

	if ((ret = syscall(SYS_close)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

void _exit(int error_code)
{
	syscall(SYS_exit, error_code);
}

char *getcwd(char *buf, size_t size)
{
	long ret;

	if ((ret = syscall(SYS_getcwd, buf, size)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
