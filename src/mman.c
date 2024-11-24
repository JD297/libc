#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long ret;

	if ((ret = syscall(__NR_mmap, addr, length, prot, flags, fd, offset)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

int munmap(void *addr, size_t length)
{
	long ret;

	if ((ret = syscall(__NR_munmap, addr, length)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags, ... /* void *new_address */)
{
	long ret;

	if ((ret = syscall(__NR_mremap, old_address, old_size, new_size, flags)) < 0) {
		SET_ERRNO_RETURN(ret);
	}

	return ret;
}
