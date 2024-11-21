#include <stdio.h>
#include <sys/utsname.h>

int main()
{
	struct utsname uts;

	if (uname(&uts) == -1) {
		return 1;
	}

	printf("%s %s %s %s %s\n", uts.sysname, uts.nodename, uts.release, uts.version, uts.machine);

	return 0;
}
