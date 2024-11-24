#include <linux/mman.h>
#include <stddef.h>
#include <sys/types.h>

#ifndef JD297_LIBC_SYS_MMAN_H
#define JD297_LIBC_SYS_MMAN_H

#define MAP_FAILED ((void *) -1)

extern void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

extern int munmap(void *addr, size_t length);

extern void *mremap(void *old_address, size_t old_size, size_t new_size, int flags, ... /* void *new_address */);

#endif
