#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	void *ret;

	register void* rdi asm ("rdi") = addr;
	register size_t rsi asm ("rsi") = length;
	register int rdx asm ("rdx") = prot;
	register int r10 asm ("r10") = flags;
	register int r8 asm ("r8") = fd;
	register off_t r9 asm ("r9") = offset;

	asm volatile
	(
		"syscall"
		: "=a" (ret)
		: "0" (SYSCALL_MMAP), "r" (rdi), "r" (rsi), "r" (rdx), "r" (r10), "r" (r8), "r" (r9)
		: "memory", "cc", "r11", "cx"
	);

	return (void *)ret;
}

int munmap(void *addr, size_t length)
{
	int ret;

	register void* rdi asm ("rdi") = addr;
	register size_t rsi asm ("rsi") = length;

	asm volatile
	(
		"syscall"
		: "=a"(ret)
		: "0"(SYSCALL_MUNMAP), "r"(addr), "r"(length)
		: "memory", "cc", "r11", "cx"
	);

	return ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags, ... /* void *new_address */)
{
	void* ret;

	register void* rdi asm ("rdi") = old_address;
	register size_t rsi asm ("rsi") = old_size;
	register size_t rdx asm ("rdx") =  new_size;
	register int r10 asm ("r10") = flags;

	asm volatile
	(
		"syscall"
		: "=a" (ret)
		: "0" (SYSCALL_MREMAP), "r" (rdi), "r" (rsi), "r" (rdx), "r" (r10)
		: "memory", "cc", "r11", "cx"
	);

	return (void *)ret;
}
