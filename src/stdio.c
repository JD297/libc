#include <stdio.h>
#include <string.h>
#include <unistd.h>

int printf(const char *restrict format, ...)
{
	va_list ap;

	va_start(ap, format);

	int nprinted = vprintf(format, ap);

	va_end(ap);

	return nprinted;
}

int vprintf(const char *restrict format, va_list ap)
{
	char *format_ptr = format;

	int nwritten = 0;

	char *conversion_specifier = "%s";

	const char *found;

	while (found = strstr(format_ptr, conversion_specifier)) {
		const char *conversion_value = va_arg(ap, char *);

		int nf = write(STDOUT_FILENO, format_ptr, strlen(format_ptr) - strlen(found));

		int ncs = write(STDOUT_FILENO, conversion_value, strlen(conversion_value));

		if (nf == -1 || ncs == -1) {
			return -1;
		}

		nwritten += nf + ncs;

		format_ptr += nf + strlen(conversion_specifier);
	}

	int n = write(STDOUT_FILENO, format_ptr, strlen(format_ptr));

	if (n == -1) {
		return -1;
	}

	nwritten += n;

	return nwritten;
}
