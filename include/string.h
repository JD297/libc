#include <types.h>

#ifndef JD297_LIBC_STRING_H
#define JD297_LIBC_STRING_H

extern void *memset(void *s, int c, size_t n);

extern size_t strlen(const char *s);

extern size_t strnlen(const char *s, size_t maxlen);

extern int strcmp(const char *s1, const char *s2);

extern int strncmp(const char *s1, const char *s2, size_t n);

extern char *strstr(const char *haystack, const char *needle);

extern void *mempcpy(void *restrict dst, const void *restrict src, size_t n);

extern char *stpcpy(char *restrict dst, const char *restrict src);

extern char *strcpy(char *restrict dst, const char *restrict src);

extern char *strcat(char *restrict dst, const char *restrict src);

#endif
