#include <errno.h>
#include <unistd.h>

int __libc_start_main(int *(main) (int, char * *, char * *), int argc, char * * ubp_av, void (*init) (void), void (*fini) (void), void (*rtld_fini) (void), void (* stack_end))
{
	program_invocation_name = ubp_av[0];
	program_invocation_short_name = ubp_av[0]; // TODO get basename

	int ret = main(argc, ubp_av, 0);

	_exit(ret);

	return ret;
}
