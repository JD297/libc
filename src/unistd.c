#include <unistd.h>

ssize_t read(unsigned int fd, char* buf, size_t count)
{
	ssize_t ret;

	asm volatile
	(
		"syscall"
		: "=a"(ret)
		: "0"(SYSCALL_READ), "D"(fd), "S"(buf), "d"(count)
	);

	return ret;
}

ssize_t write(unsigned int fd, const char *buf, size_t count)
{
	ssize_t ret;

	asm volatile
	(
		"syscall"
		: "=a"(ret)
		: "0"(SYSCALL_WRITE), "D"(fd), "S"(buf), "d"(count)
	);

	return ret;
}

void _exit(int error_code)
{
	int ret;

	asm volatile
	(
		"syscall"
		: "=a" (ret)
		: "0"(SYSCALL_EXIT), "D"(error_code)
	);
}
