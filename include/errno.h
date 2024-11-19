#ifndef JD297_LIBC_ERRNO_H
#define JD297_LIBC_ERRNO_H

extern int errno;

#define SET_ERRNO_RETURN(RET) errno = RET; return -1

#endif
