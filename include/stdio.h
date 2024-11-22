#include <stdarg.h>

#ifndef JD297_LIBC_STDIO_H
#define JD297_LIBC_STDIO_H

#define fileno(stream) ~(intptr_t)stream

typedef struct FILE {
	char dummy[1];
} FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;


extern int printf(const char *restrict format, ...);

extern int fprintf(FILE *restrict stream, const char *restrict format, ...);

extern int vfprintf(FILE *restrict stream, const char *restrict format, va_list ap);

extern int vprintf(const char *restrict format, va_list ap);

#endif
