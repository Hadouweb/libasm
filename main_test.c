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

int		main(void)
{
	printf("\n");
	TEST(ft_bzero)
	return (0);
}
