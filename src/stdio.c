#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

FILE *stdin	= (FILE*)(intptr_t)~STDIN_FILENO;
FILE *stdout	= (FILE*)(intptr_t)~STDOUT_FILENO;
FILE *stderr	= (FILE*)(intptr_t)~STDERR_FILENO;

int printf(const char *restrict format, ...)
{
	va_list ap;

	va_start(ap, format);

	int nprinted = vprintf(format, ap);

	va_end(ap);

	return nprinted;
}

int fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	va_list ap;

	va_start(ap, format);

	int nprinted = vfprintf(stream, format, ap);

	va_end(ap);

	return nprinted;
}

int vfprintf(FILE *restrict stream, const char *restrict format, va_list ap)
{
	const char *restrict format_ptr = format;

	int nwritten = 0;

	char *conversion_specifier = "%s";

	const char *found;

	while ((found = strstr(format_ptr, conversion_specifier)) != NULL) {
		const char *conversion_value = va_arg(ap, char *);

		int nf = write(fileno(stream), format_ptr, strlen(format_ptr) - strlen(found));

		int ncs = write(fileno(stream), conversion_value, strlen(conversion_value));

		if (nf == -1 || ncs == -1) {
			return -1;
		}

		nwritten += nf + ncs;

		format_ptr += nf + strlen(conversion_specifier);
	}

	int n = write(fileno(stream), format_ptr, strlen(format_ptr));

	if (n == -1) {
		return -1;
	}

	nwritten += n;

	return nwritten;
}

int vprintf(const char *restrict format, va_list ap)
{
	return vfprintf(stdout, format, ap);
}
