#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "/usr/local/bin:/usr/bin:/bin";
	char *saveptr1;

	char* tok = strtok_r(str, ":", &saveptr1);

	while (tok != NULL) {
		printf("%s\n", tok);

		tok = strtok_r(NULL, ":", &saveptr1);
	}

	return 0;
}
