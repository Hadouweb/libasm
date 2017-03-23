#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>
#include "libfts.h"

# define ENABLE_ft_bzero 1
# define ENABLE_ft_strcat 1
# define ENABLE_ft_isalpha 1
# define ENABLE_ft_isdigit 1
# define ENABLE_ft_isalnum 1
# define ENABLE_ft_isascii 1
# define ENABLE_ft_isprint 1
# define ENABLE_ft_toupper 1
# define ENABLE_ft_tolower 1
# define ENABLE_ft_puts 1
# define ENABLE_ft_strlen 1
# define ENABLE_ft_memset 1
# define ENABLE_ft_memcpy 1
# define ENABLE_ft_strdup 1
# define ENABLE_ft_cat 1

# define TEST(F) {\
	if (ENABLE_##F) {\
		if (test_##F() == 1) {\
			printf("\033[32;1mSUCCESS:\033[0m %s\n", #F);\
		} else\
			printf("\033[31;1mFAILED:\033[0m %s\n", #F);\
	}\
}\

int		test_ft_bzero(void)
{
	char	control[10];
	char	control2[] = "123456789";
	char	subject[] = "123456789";
	char	subject2[] = "123456789";

	bzero(control, 10);
	ft_bzero(subject, 10);
	if (memcmp(control, subject, 10) != 0)
		return 0;

	subject[0] = 'a';
	ft_bzero(subject, 0);
	if (subject[0] != 'a')
		return 0;

	bzero(control2, 3);
	ft_bzero(subject2, 3);
	if (memcmp(subject2, control2, 10) != 0)
		return 0;
	return 1;
}

int		test_ft_strcat(void)
{
	char	buf[42];

	bzero(buf, 42);
	ft_strcat(buf, "Hello");
	ft_strcat(buf, " World");
	ft_strcat(buf, "!");
	ft_strcat(buf, "");
	if (strcmp(buf, "Hello World!") != 0)
		return 0;
	if (buf != ft_strcat(buf, ""))
		return 0;
	return 1;
}

int		test_ft_isdigit(void)
{
	int 	i = '0';
	while (i <= '9')
	{
		if (ft_isdigit(i) == 0)
			return 0;
		i++;
	}
	if (ft_isdigit(0) != 0)
		return 0;
	if (ft_isdigit(47) != 0)
		return 0;
	if (ft_isdigit(-1) != 0)
		return 0;
	if (ft_isdigit(123) != 0)
		return 0;
	return 1;
}

int		test_ft_isalnum(void)
{
	int 	i = '0';
	while (i <= '9')
	{
		if (ft_isalnum(i) == 0)
			return 0;
		i++;
	}
	i = 'A';
	while (i <= 'Z')
	{
		if (ft_isalnum(i) == 0)
			return 0;
		i++;
	}
	i = 'a';
	while (i <= 'z')
	{
		if (ft_isalnum(i) == 0)
			return 0;
		i++;
	}
	if (ft_isalnum(0) != 0)
		return 0;
	if (ft_isalnum(47) != 0)
		return 0;
	if (ft_isalnum(-1) != 0)
		return 0;
	if (ft_isalnum(123) != 0)
		return 0;
	return 1;
}

int		test_ft_isascii(void)
{
	int 	i = 0;
	while (i <= 127)
	{
		if (ft_isascii(i) == 0)
			return 0;
		i++;
	}
	if (ft_isascii(173) != 0)
		return 0;
	if (ft_isascii(-1) != 0)
		return 0;
	if (ft_isascii(2000) != 0)
		return 0;
	return 1;
}

int		test_ft_isprint(void)
{
	int 	i = 32;
	while (i <= 126)
	{
		if (ft_isprint(i) == 0)
			return 0;
		i++;
	}
	if (ft_isprint(31) != 0)
		return 0;
	if (ft_isprint(-1) != 0)
		return 0;
	if (ft_isprint(127) != 0)
		return 0;
	return 1;
}

int 	test_ft_toupper(void)
{
	int 	i = 'a';
	while (i <= 'z')
	{
		if (ft_toupper(i) != (i - 32))
			return 0;
		i++;
	}
	i = 'A';
	while (i <= 'Z')
	{
		if (ft_toupper(i) != i)
			return 0;
		i++;
	}
	if (ft_toupper(31) != 31)
		return 0;
	if (ft_toupper(-1) != -1)
		return 0;
	if (ft_toupper(127) != 127)
		return 0;
	return 1;
}

int 	test_ft_tolower(void)
{
	int 	i = 'a';
	while (i <= 'z')
	{
		if (ft_tolower(i) != i)
			return 0;
		i++;
	}
	i = 'A';
	while (i <= 'Z')
	{
		if (ft_tolower(i) != i + 32)
			return 0;
		i++;
	}
	if (ft_tolower(31) != 31)
		return 0;
	if (ft_tolower(-1) != -1)
		return 0;
	if (ft_tolower(127) != 127)
		return 0;
	return 1;
}

int 	test_ft_puts(void)
{
	int		ret;
	int		puts_ret1;
	//int		puts_ret2;
	int		out;
	int		p[2];
	char	buf[10000];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	puts_ret1 = ft_puts("aaa");
	//puts_ret2 = ft_puts(NULL);
	dup2(out, 1);
	ret = read(p[0], buf, 10000);
	buf[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (puts_ret1 <= 0)
		return 0;
	//if (puts_ret2 <= 0)
	//	return 0;
	if (strcmp(buf, "aaa\n(null)\n") != 0)
		return 0;
	return 1;
}

int 	test_ft_strlen(void)
{
	int test_len = 10 * 1000 * 1000;
	char *str = malloc(sizeof(char) * test_len);;

	memset(str, 'a', test_len);
	str[test_len - 1] = '\0';
	if (ft_strlen(str) != strlen(str))
		return 0;
	str[0] = '\0';
	if (ft_strlen(str) != strlen(str))
		return 0;
	free(str);
	return 1;
}

int 	test_ft_memset(void)
{
	char	b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	if (memset(b1, 99, 0) != ft_memset(b1, 99, 0))
		return 0;
	if ((memcmp(b1, b2, 100) != 0))
		return 0;
	b1[0] = 1;
	ft_memset(b1, 0, 0);
	if (b1[0] != 1)
		return 0;
	return 1;
}

int 	test_ft_memcpy(void)
{
	char	b1[100], b2[100];

	memset(b1, 33, 100);
	memset(b2, 63, 100);
	ft_memcpy(b1, b2, 100);
	if (memcmp(b1, b2, 100) != 0)
		return 0;
	if (ft_memcpy(b1, b2, 0) != b1)
		return 0;
	return 1;
}

int 	test_ft_strdup(void)
{
	char	*c;

	c = "AbC";
	if (c == ft_strdup(c))
		return 0;
	if (strcmp(ft_strdup("aaaaa"), "aaaaa") != 0)
		return 0;
	if (strcmp(ft_strdup(""), "") != 0)
		return 0;
	return 1;
}

int 	test_ft_cat(void)
{
	int 	pids[2];
	char 	buf[20];
	int 	cpy_stdout;
	int 	fd;

	cpy_stdout = dup(1);
	pipe(pids);
	dup2(pids[1], 1);

	system("echo '_ _ Hello World \t OK' > catout");
	fd = open("catout", O_RDONLY);
	if (fd == -1)
		return 0;
	ft_cat(fd);
	read(pids[0], buf, 20);
	dup2(cpy_stdout, 1);

	close(fd);
	close(pids[0]);
	close(pids[1]);
	close(cpy_stdout);
	system("rm catout");
	if (memcmp(buf, "_ _ Hello World \t OK", 20) != 0)
		return 0;
	ft_cat(-1);
	return 1;
}

int		main(void)
{
	printf("\n");
	TEST(ft_bzero)
	TEST(ft_strcat)
	TEST(ft_isdigit)
	TEST(ft_isalnum)
	TEST(ft_isascii)
	TEST(ft_isprint)
	TEST(ft_toupper)
	TEST(ft_tolower)
	TEST(ft_puts)
	TEST(ft_strlen)
	TEST(ft_memset)
	TEST(ft_memcpy)
	TEST(ft_strdup)
	TEST(ft_cat)
	return (0);
}
