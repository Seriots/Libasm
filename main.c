// main.c

#include <stdio.h>
#include <string.h>

extern int test(int a, int b, int c, float d); // Déclaration de la fonction test() définie dans libasm.a
extern void hello_world(char* message, int length);
extern int ft_strlen(char *str);

int strlength(char *str) {
	int i = 0;

	while (str && str[i]) {
		i++;
	}
	return i;
}

int main()
{
    char message[] = "Hello, World!\n";
	//int length = sizeof(message);

	printf("Calling test() from libasma.a...\n");
	printf("%d\n", test(7, 3, 11, 5.0)); // Appel de la fonction test() définie dans libasm.a

	//hello_world(message, length);
	printf("string_input = %d, %d, %ld\n", ft_strlen(message), strlength(message), strlen(message));
	return 0;
}