// main.c

#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
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

void strcmp_test()
{
	const char *wit = "Witness";
	const char *even = "Witness";
	const char *more = "Witneu";
	const char *less = "Witnesswe";
	const char *empty = "";

	size_t checkres = 0;

	printf("\n-----------Test strcmp-----------\n");
	
	checkres = strcmp(wit, even) == ft_strcmp(wit, even);
	printf("TEST: strcmp('Witness', 'Witness') -> standard = %d / ft = %d -> %s%s%s", strcmp(wit, even), ft_strcmp(wit, even), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);
	
	checkres = strcmp(wit, more) == ft_strcmp(wit, more);
	printf("TEST: strcmp('Witness', 'Witneu') -> standard = %d / ft = %d -> %s%s%s", strcmp(wit, more), ft_strcmp(wit, more), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strcmp(more, wit) == ft_strcmp(more, wit);
	printf("TEST: strcmp('Witneu', 'Witness') -> standard = %d / ft = %d -> %s%s%s", strcmp(more, wit), ft_strcmp(more, wit), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strcmp(wit, less) == ft_strcmp(wit, less);
	printf("TEST: strcmp('Witness', 'Witnesswe') -> standard = %d / ft = %d -> %s%s%s", strcmp(wit, less), ft_strcmp(wit, less), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strcmp(less, wit) == ft_strcmp(less, wit);
	printf("TEST: strcmp('Witnesswe', 'Witness') -> standard = %d / ft = %d -> %s%s%s", strcmp(less, wit), ft_strcmp(less, wit), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strcmp(wit, empty) == ft_strcmp(wit, empty);
	printf("TEST: strcmp('Witness', '') -> standard = %d / ft = %d -> %s%s%s", strcmp(wit, empty), ft_strcmp(wit, empty), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);

	checkres = strcmp(empty, wit) == ft_strcmp(empty, wit);
	printf("TEST: strcmp('', 'Witness') -> standard = %d / ft = %d -> %s%s%s", strcmp(empty, wit), ft_strcmp(empty, wit), checkres ? GREEN : RED, checkres ? "OK\n" : "KO\n", RESET);
}

int main()
{
	strlen_test();

	strcpy_test();

	strcmp_test();

	return 0;
}