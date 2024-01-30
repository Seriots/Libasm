// main.c

#include <stdio.h>

extern int test(int a, int b, int c, float d); // Déclaration de la fonction test() définie dans libasm.a
extern void hello_world(char* message, int length);

int main()
{
    char message[] = "Hello, World!\n";
    int length = 15;

	printf("Calling test() from libasma.a...\n");
	printf("%d\n", test(7, 3, 11, 5.0)); // Appel de la fonction test() définie dans libasm.a

    hello_world(message, length);
	return 0;
}