#ifndef JD297_LIBC_STDLIB_H
#define JD297_LIBC_STDLIB_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

extern void exit(int status);

extern void *malloc(size_t size);

extern void free(void *_Nullable ptr);

extern void *calloc(size_t nmemb, size_t size);

extern void *realloc(void *_Nullable ptr, size_t size);

extern void *reallocarray(void *_Nullable ptr, size_t nmemb, size_t size);

#endif
