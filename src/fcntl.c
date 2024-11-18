#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/syscall.h>
#include <types.h>
#include <unistd.h>

int open(const char *filename, int flags, ...)
{
        long ret;

	va_list ap;

	va_start(ap, flags);

	if ((ret = syscall(3, filename, flags, va_arg(ap, mode_t))) < 0) {
		va_end(ap);

		SET_ERRNO_RETURN(ret);
	}

	va_end(ap);

        return ret;
}
