#include <string.h>

void *memset(void *s, int c, size_t n)
{
	for(size_t i = 0; i < n; i++) {
		((char *)s)[i] = c;
	}

	return s;
}

size_t strlen(const char *s)
{
	size_t len;

	for (len = 0; s[len] != '\0'; len++);

	return len;
}

size_t strnlen(const char *s, size_t maxlen)
{
	size_t len;

	for (len = 0; maxlen > len || s[len] != '\0'; len++); // TODO CHECK LOGIC

	return len;
}

int strcmp(const char *s1, const char *s2)
{
	unsigned char cmp = 0;

	for (size_t i = 0; ; i++) {
		cmp = s1[i] - s2[i];

		if (cmp != 0) {
			break;
		}
	}

	return cmp;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char cmp = 0;

	for (size_t i = 0; i < n; i++) {
		cmp = s1[i] - s2[i];

		if (cmp != 0) {
			break;
		}
	}

	return cmp;
}

char *strstr(const char *haystack, const char *needle)
{
	if (needle[0] == '\0') {
		return haystack;
	}

	size_t haystack_len = strlen(haystack);

	size_t needle_len = strlen(needle);

	if (haystack_len < needle_len) {
		return NULL;
	}

	for (size_t i = 0; i < haystack_len - needle_len; i++) {
		if (strncmp(haystack + i, needle, needle_len) == 0) {
			return haystack + i;
		}
	}

	return NULL;
}

void *mempcpy(void *restrict dst, const void *restrict src, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		((char *)dst)[i] = ((char *)src)[i];
	}

	return (char *)dst + n;
}

char *stpcpy(char *restrict dst, const char *restrict src)
{
	char *p;

	p = mempcpy(dst, src, strlen(src));
	*p = '\0';

	return p;
}

char *strcpy(char *restrict dst, const char *restrict src)
{
	stpcpy(dst, src);

	return dst;
}

char *strcat(char *restrict dst, const char *restrict src)
{
	stpcpy(dst + strlen(dst), src);

	return dst;
}
