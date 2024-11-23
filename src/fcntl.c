#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

int open(const char *filename, int flags, ...)
{
        long ret;

	va_list ap;

	va_start(ap, flags);

	mode_t mode = 0;

	// TODO check flags contains O_CREAT or O_TMFILE
	// mode = *va_arg(ap, mode_t);

	if ((ret = syscall(SYS_open, filename, flags, mode)) < 0) {
		va_end(ap);

		SET_ERRNO_RETURN(ret);
	}

	va_end(ap);

        return ret;
}
