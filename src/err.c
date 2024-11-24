#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err(int eval, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);

	fprintf(stderr, "%s: ", program_invocation_name);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, ": %s\n", strerror(errno));

	va_end(ap);

	exit(eval);
}
