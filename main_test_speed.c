#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>
#include "libfts.h"
//#include "libft.h"

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

typedef struct 		s_timer
{
	clock_t 		start;
	clock_t 		diff1;
	clock_t 		diff2;
	clock_t 		diff3;
}					t_timer;

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

# define nb_loob 10000000

int		main(void)
{
	printf("\n");
	TEST(ft_memset)

	t_timer timer;

	int 	i;
	char	b1[100], b2[100], b3[100];

	/*timer.start = clock();
	i = nb_loob;
	while (i--)
		ft_memset(b1, 42, 100);
	timer.diff1 = clock() - timer.start;*/

	timer.start = clock();
	i = nb_loob;
	while (i--)
		memset(b2, 42, 100);
	timer.diff2 = clock() - timer.start;

	timer.start = clock();
	i = nb_loob;
	while (i--)
		ft_memset(b3, 42, 100);
	timer.diff3 = clock() - timer.start;

	//int msec1 = timer.diff1 * 1000 / CLOCKS_PER_SEC;
	int msec2 = timer.diff2 * 1000 / CLOCKS_PER_SEC;
	int msec3 = timer.diff3 * 1000 / CLOCKS_PER_SEC;
	//printf("FT  : %d,%d\n", msec1/1000, msec1%1000);
	printf("STD : %d,%d\n", msec2/1000, msec2%1000);
	printf("ASM : %d,%d\n", msec3/1000, msec3%1000);

	return (0);
}
