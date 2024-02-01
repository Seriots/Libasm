// main.c

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;


extern size_t ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);
extern int ft_atoi_base(char *str, char *base);
extern int test();
extern void ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin_list);
extern void ft_list_sort(t_list **begin_list, int (*cmp)());
extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

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

void write_test()
{
	int ret = 0;

	printf("\n-----------Test Write------------\n");

	printf("\n");

	ret = write(1, "hello world", 11);
	perror(" -> write");
	printf("-> TEST: write(1, 'hello world', 11) -> standard = %d\n", ret);

	ret = ft_write(1, "hello world", 11);
	perror(" -> write");
	printf("-> TEST: ft_write(1, 'hello world', 11) -> standard = %d\n", ret);

	printf("\n");
	ret = write(4, "hello world", 11);
	perror(" -> write");
	printf("-> TEST: write(4, 'hello world', 11) -> standard = %d\n", ret);

	ret = ft_write(4, "hello world", 11);
	perror(" -> write");
	printf("-> TEST: ft_write(1, 'hello world', 11) -> standard = %d\n", ret);

	printf("\n");
	ret = write(1, "hello world", 5);
	perror(" -> write");
	printf("-> TEST: write(1, 'hello world', 5) -> standard = %d\n", ret);

	ret = ft_write(1, "hello world", 5);
	perror(" -> write");
	printf("-> TEST: ft_write(1, 'hello world', 5) -> standard = %d\n", ret);
	printf("\n");
}

void read_test()
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test.txt", O_WRONLY);
	char buf[100];
	printf("\n-----------Test Read------------\n");

	printf("TEST: ft_read(fd, buf, 100) -> size: %zd -- %s\n", ft_read(fd, 0, 10), buf);
	perror(" -> read");

		printf("TEST: ft_read(fd, buf, 100) -> size: %zd -- %s\n", read(fd, 0, 10), buf);
	perror(" -> read");

		printf("TEST: ft_read(fd, buf, 100) -> size: %zd -- %s\n", ft_read(fd, buf, 10), buf);
	perror(" -> read");

		printf("TEST: ft_read(fd, buf, 100) -> size: %zd -- %s\n", read(fd, buf, 10), buf);
	perror(" -> read");

			printf("TEST: ft_read(fd, buf, 100) -> size: %zd -- %s\n", ft_read(fd2, buf, 10), buf);
	perror(" -> read");

		printf("TEST: ft_read(fd, buf, 100) -> size: %zd -- %s\n", read(fd2, buf, 10), buf);
	perror(" -> read");
}

void strdup_test()
{
	printf("\n-----------Test Strdup------------\n");


	const char *a = "";

	printf("a = %s\n", a);
	char *b = ft_strdup(a);
	printf("a = %s, b = %s\n", a, b);

	// a[0] = 'b';

	// printf("a = %s, b = %s\n", a, b);

	free(b);

	char c[5] = "";

	printf("c = %s\n", c);
	char *d = ft_strdup(c);
	printf("c = %s, d = %s\n", c, d);

	c[0] = 'd';

	printf("c = %s, d = %s\n", c, d);

	free(d);

	char e[5] = "yolo";

	printf("e = %s\n", e);
	char *f = ft_strdup(e);
	printf("e = %s, f = %s\n", e, f);

	e[0] = 'f';

	printf("e = %s, f = %s\n", e, f);

	free(d);
}

void atoi_base_test()
{
	printf("\n-----------Test Atoi------------\n");

	printf("TEST: ft_atoi_base('5120', '0123456789') -> %d\n", ft_atoi_base("5120", "0123456789"));
	printf("TEST: ft_atoi_base('A3F', '0123456789ABCDEF') -> %d\n", ft_atoi_base("A3F", "0123456789ABCDEF"));
	printf("TEST: ft_atoi_base('-A3F', '0123456789ABCDEF') -> %d\n", ft_atoi_base("-A3F", "0123456789ABCDEF"));
	printf("TEST: ft_atoi_base('+A3F', '0123456789ABCDEF') -> %d\n", ft_atoi_base("+A3F", "0123456789ABCDEF"));
	printf("TEST: ft_atoi_base('5120', '0123451') -> %d\n", ft_atoi_base("5120", "0123451"));
	printf("TEST: ft_atoi_base('5120', '012345+') -> %d\n", ft_atoi_base("5120", "012345+"));
	printf("TEST: ft_atoi_base('', '') -> %d\n", ft_atoi_base("", ""));
	printf("TEST: ft_atoi_base('0000', '0') -> %d\n", ft_atoi_base("0000", "0"));
	printf("TEST: ft_atoi_base('51A20', '0123456789') -> %d\n", ft_atoi_base("51A20", "0123456789"));
	printf("TEST: ft_atoi_base('51A20', '01234567 89') -> %d\n", ft_atoi_base("51A20", "0123456 789"));
	printf("TEST: ft_atoi_base('51A20', '\\n0123456789') -> %d\n", ft_atoi_base("51A20", "\n0123456789"));

}
int lower(void *d1, void *d2)
{return ((long long)d1 > (long long)d2);}

int main()
{
	//strlen_test();

	//strcpy_test();

	//strcmp_test();

	//write_test();

	//read_test();

	//strdup_test();

	//atoi_base_test();

	t_list *start = NULL;
	t_list *start2 = NULL;

	ft_list_push_front(&start, (void *)5);
	ft_list_push_front(&start, (void *)3);
	ft_list_push_front(&start, (void *)-2);
	ft_list_push_front(&start, (void *)4);
	ft_list_push_front(&start, (void *)8);
	ft_list_push_front(&start, (void *)-1);

	ft_list_push_front(&start2, "dfedefzef");
	ft_list_push_front(&start2, "qswCzac");
	ft_list_push_front(&start2, "azqaadv");
	ft_list_push_front(&start2, "vethfbv");
	ft_list_push_front(&start2, "fgtrfbdv");
	ft_list_push_front(&start2, "qascW");
	ft_list_push_front(&start2, "byrn");


	ft_list_sort(&start, &lower);
	ft_list_sort(&start2, &strcmp);

	t_list* tmp = start;
	while (tmp != NULL)
	{
		printf("-> %d\n", (int)tmp->data);
		tmp = tmp->next;
	}

	ft_list_remove_if(&start, (void *)5, &lower, &free);

	t_list* tmp2 = start;
	while (tmp2 != NULL)
	{
		printf("-> %d\n", (int)tmp2->data);
		tmp2 = tmp2->next;
	}

	while (start2 != NULL)
	{
		printf("-> %s\n", (char *)start2->data);
		start2 = start2->next;
	}
	return 0;
}