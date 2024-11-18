#ifndef JD297_LIBC_ERRNO_H
#define JD297_LIBC_ERRNO_H

int errno;

#define SET_ERRNO_RETURN(RET) errno = RET; return -1

#endif
