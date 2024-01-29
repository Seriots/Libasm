// main.c

#include <stdio.h>

extern int test(); // Déclaration de la fonction test() définie dans libasm.a

int main()
{
	printf("Calling test() from libasma.a...\n");
	printf("%d\n", test()); // Appel de la fonction test() définie dans libasm.a
	return 0;
}