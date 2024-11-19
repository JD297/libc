#include <string.h>

int main()
{
	if (strcmp("Tests strcmp() is eq same length.", "Tests strcmp() is eq same length.") != 0) {
		return 1;
	}

	int a = strcmp("Tests strcmp() is eq.AB", "Tests strcmp() is eq.A");

	int b = strcmp("Tests strcmp() is eq.A", "Tests strcmp() is eq.AB");

	return a + b;
}
