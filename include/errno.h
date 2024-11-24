#include <linux/errno.h>

#ifndef JD297_LIBC_ERRNO_H
#define JD297_LIBC_ERRNO_H

extern int errno;

extern char *program_invocation_name;
extern char *program_invocation_short_name;

#define SET_ERRNO_RETURN(RET) errno = RET; return -1

#endif
