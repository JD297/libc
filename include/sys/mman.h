#include <types.h>

#ifndef JD297_LIBC_SYS_MMAN_H
#define JD297_LIBC_SYS_MMAN_H

#define SYSCALL_MMAP	9
#define SYSCALL_MUNMAP	11
#define SYSCALL_MREMAP	25

#define PROT_NONE       0x0
#define PROT_READ	0x1
#define PROT_WRITE	0x2
#define PROT_EXEC	0x4

#define MAP_FILE		0x00
#define MAP_SHARED		0x01
#define MAP_PRIVATE		0x02
#define MAP_SHARED_VALIDATE	0x03
#define MAP_FIXED		0x10
#define MAP_ANONYMOUS		0x20
#define MAP_ANON		MAP_ANONYMOUS
#define MAP_GROWSDOWN		0x00100
#define MAP_DENYWRITE		0x00800
#define MAP_EXECUTABLE		0x01000
#define MAP_LOCKED		0x02000
#define MAP_NORESERVE		0x04000
#define MAP_POPULATE		0x08000
#define MAP_NONBLOCK		0x10000
#define MAP_STACK       	0x20000
#define MAP_HUGETLB		0x40000
#define MAP_SYNC		0x80000
#define MAP_FIXED_NOREPLACE 	0x100000

#define MAP_HUGE_SHIFT	26
#define MAP_HUGE_MASK	0x3f

#define MAP_HUGE_16KB	(14 << MAP_HUGE_SHIFT)
#define MAP_HUGE_64KB	(16 << MAP_HUGE_SHIFT)
#define MAP_HUGE_512KB	(19 << MAP_HUGE_SHIFT)
#define MAP_HUGE_1MB	(20 << MAP_HUGE_SHIFT)
#define MAP_HUGE_2MB	(21 << MAP_HUGE_SHIFT)
#define MAP_HUGE_8MB	(23 << MAP_HUGE_SHIFT)
#define MAP_HUGE_16MB	(24 << MAP_HUGE_SHIFT)
#define MAP_HUGE_32MB	(25 << MAP_HUGE_SHIFT)
#define MAP_HUGE_256MB	(28 << MAP_HUGE_SHIFT)
#define MAP_HUGE_512MB	(29 << MAP_HUGE_SHIFT)
#define MAP_HUGE_1GB	(30 << MAP_HUGE_SHIFT)
#define MAP_HUGE_2GB	(31 << MAP_HUGE_SHIFT)
#define MAP_HUGE_16GB	(34U << MAP_HUGE_SHIFT)

#define MREMAP_MAYMOVE		1
#define MREMAP_FIXED		2
#define MREMAP_DONTUNMAP	4

extern void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

extern int munmap(void *addr, size_t length);

extern void *mremap(void *old_address, size_t old_size, size_t new_size, int flags, ... /* void *new_address */);

#endif
