#include <stdlib.h>
#include <unistd.h>

void exit(int status)
{
	_exit(status); // TODO SEE MAN 3 exit this is just a functional but not correct implementation!
}
