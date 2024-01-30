// main.c

#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern char *string_test(char *dest);

const char *GREEN = "\e[0;32m";
const char *RED = "\e[0;31m";
const char *RESET = "\e[0;0m";

void strlen_test()
{

	char *test1 = "hello world";
	char *test2 = "h";
	char *test3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	size_t checkres = 0;

	printf("-----------Test strlen-----------\n");
	
	checkres = strlen(test1) == ft_strlen(test1);
	printf("TEST: strlen('hello world') -> standard = %ld / ft = %ld -> %s%s%s", strlen(test1), ft_strlen(test1), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strlen(test2) == ft_strlen(test2);
	printf("TEST: strlen('h') -> standard = %ld / ft = %ld -> %s%s%s", strlen(test2), ft_strlen(test2), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strlen(test3) == ft_strlen(test3);
	printf("TEST: strlen('aa..aaa (x257)') -> standard = %ld / ft = %ld -> %s%s%s", strlen(test3), ft_strlen(test3), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

}

void strcpy_test()
{
	char *test1 = "hello world";
	char *test2 = "";
	char test3[50] = "";
	char test4[50] = "";

	size_t checkres = 0;

	printf("\n-----------Test strcpy-----------\n");

	checkres = strlen(strcpy(test3, test1)) == strlen(ft_strcpy(test4, test1));
	printf("TEST: strcpy('hello world') -> standard = %s / ft = %s -> %s%s%s", test3, test4, checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strlen(strcpy(test3, test2)) == strlen(ft_strcpy(test4, test2));
	printf("TEST: strcpy('') -> standard = %s / ft = %s -> %s%s%s", test3, test4, checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

}

int main()
{
	strlen_test();

	strcpy_test();


	return 0;
}