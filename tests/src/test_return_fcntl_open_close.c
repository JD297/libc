#include <errno.h>
#include <fcntl.h>

int main ()
{
	int fd;

	if ((fd = open(__FILE__, O_RDONLY)) == -1) {
		return errno;
	}

	if (close(fd) == -1) {
		return errno;
	}

	return 0;
}
