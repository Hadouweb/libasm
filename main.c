/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlouise <davidlouiz@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 02:10:35 by dlouise           #+#    #+#             */
/*   Updated: 2017/03/25 09:49:37 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Les tests definis ici seront effectues
#define TEST_MEMSET
#define TEST_BZERO
#define TEST_MEMCPY
//#define TEST_MEMCCPY
//#define TEST_MEMMOVE
//#define TEST_MEMCHR
#define TEST_MEMCMP
#define TEST_STRLEN
#define TEST_STRDUP
//#define TEST_STRCPY
//#define TEST_STRNCPY
#define TEST_STRCAT
//#define TEST_STRNCAT
//#define TEST_STRLCAT
//#define TEST_STRCHR
//#define TEST_STRRCHR
//#define TEST_STRSTR
//#define TEST_STRNSTR
//#define TEST_STRCMP
//#define TEST_STRNCMP
//#define TEST_ATOI
#define TEST_ISALPHA
#define TEST_ISDIGIT
#define TEST_ISALNUM
#define TEST_ISASCII
#define TEST_ISPRINT
#define TEST_TOUPPER
#define TEST_TOLOWER
#define TEST_PUTS
#define TEST_CAT
//#define TEST_PUTCHAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include "libft.h"

int     test_memset(void);
int     test_bzero(void);
int     test_memcpy(void);
int     test_memccpy(void);
int     test_memmove(void);
int     test_memchr(void);
int     test_memcmp(void);
int     test_strlen(void);
int     test_strdup(void);
int     test_strcpy(void);
int     test_strncpy(void);
int     test_strcat(void);
int     test_strncat(void);
int     test_strlcat(void);
int     test_strchr(void);
int     test_strrchr(void);
int     test_strstr(void);
int     test_strnstr(void);
int     test_strcmp(void);
int     test_strncmp(void);
int     test_atoi(void);
int     test_isalpha(void);
int     test_isdigit(void);
int     test_isalnum(void);
int     test_isascii(void);
int     test_isprint(void);
int     test_toupper(void);
int     test_tolower(void);
int     test_puts(void);
int     test_cat(void);
int     test_putchar(void);

#define ERROR() { printf("Line %d, ", __LINE__ - 1); return (0); }
#define ADD_TEST(NAME) add_test(tests_list, #NAME, test_##NAME)

typedef struct  s_test
{
    int         (*f)(void);
    char        *name;
    char        added;
}               t_test;

void    add_test(t_test *tests_list, char *name, int (*f)(void))
{
    static int  i = 0;

    tests_list[i].f = f;
    tests_list[i].name = name;
    tests_list[i].added = 1;
    i++;
}

int     main(void)
{
    t_test  tests_list[100];
    int     i;
    pid_t   pid;
    int     status;

    memset(tests_list, 0, 100 * sizeof(t_test));


#ifdef TEST_MEMSET
    ADD_TEST(memset);
#endif
#ifdef TEST_BZERO
    ADD_TEST(bzero);
#endif
#ifdef TEST_MEMCPY
    ADD_TEST(memcpy);
#endif
#ifdef TEST_MEMCCPY
    ADD_TEST(memccpy);
#endif
#ifdef TEST_MEMMOVE
    ADD_TEST(memmove);
#endif
#ifdef TEST_MEMCHR
    ADD_TEST(memchr);
#endif
#ifdef TEST_MEMCMP
    ADD_TEST(memcmp);
#endif
#ifdef TEST_STRLEN
    ADD_TEST(strlen);
#endif
#ifdef TEST_STRDUP
    ADD_TEST(strdup);
#endif
#ifdef TEST_STRCPY
    ADD_TEST(strcpy);
#endif
#ifdef  TEST_STRNCPY
    ADD_TEST(strncpy);
#endif
#ifdef  TEST_STRCAT
    ADD_TEST(strcat);
#endif
#ifdef  TEST_STRNCAT
    ADD_TEST(strncat);
#endif
#ifdef  TEST_STRLCAT
    ADD_TEST(strlcat);
#endif
#ifdef  TEST_STRCHR
    ADD_TEST(strchr);
#endif
#ifdef  TEST_STRRCHR
    ADD_TEST(strrchr);
#endif
#ifdef  TEST_STRSTR
    ADD_TEST(strstr);
#endif
#ifdef  TEST_STRNSTR
    ADD_TEST(strnstr);
#endif
#ifdef  TEST_STRCMP
    ADD_TEST(strcmp);
#endif
#ifdef  TEST_STRNCMP
    ADD_TEST(strncmp);
#endif
#ifdef  TEST_ATOI
    ADD_TEST(atoi);
#endif
#ifdef  TEST_ISALPHA
    ADD_TEST(isalpha);
#endif
#ifdef  TEST_ISDIGIT
    ADD_TEST(isdigit);
#endif
#ifdef  TEST_ISALNUM
    ADD_TEST(isalnum);
#endif
#ifdef  TEST_ISASCII
    ADD_TEST(isascii);
#endif
#ifdef  TEST_ISPRINT
    ADD_TEST(isprint);
#endif
#ifdef  TEST_TOUPPER
    ADD_TEST(toupper);
#endif
#ifdef  TEST_TOLOWER
    ADD_TEST(tolower);
#endif
#ifdef  TEST_PUTS
    ADD_TEST(puts);
#endif
#ifdef  TEST_CAT
    ADD_TEST(cat);
#endif
#ifdef  TEST_PUTCHAR
    ADD_TEST(putchar);
#endif

    i = 0;
    while (tests_list[i].added)
    {
        printf("ft_%s : ", tests_list[i].name);
        fflush(stdout);
        pid = fork();
        // Cas du fils
        if (0 == pid)
        {
            alarm(3);
            if (1 == tests_list[i].f())
                printf("\033[32mOK\033[0m\n");
            else
                printf("\033[31mKO\033[0m\n");
            exit(0);
        }
        // Cas du pere
        else
        {
            if (-1 != wait(&status) && WIFSIGNALED(status))
            {
                switch(WTERMSIG(status))
                {
                    case SIGSEGV:
                        printf("\033[31mSegmentation Fault\033[0m\n");
                        break;
                    default:
                        printf("\033[31mKO Sig %d\033[0m\n", WTERMSIG(status));
                }
            }
        }

        i++;
    }

    return (0);
}

#ifdef TEST_MEMSET
int     test_memset(void)
{
    char tab[10];

    if (NULL != ft_memset(NULL, 0, 0))
        ERROR();
    if (ft_memset(tab, 'a', 10) != tab)
        ERROR();
    if (0 != memcmp("aaaaaaaaaa", tab, 10))
        ERROR();
    ft_memset(tab + 1, 'b' | 0xff00, 8);
    if (0 != memcmp("abbbbbbbba", tab, 10))
        ERROR();
    return (1);
}
#endif

#ifdef TEST_BZERO
int     test_bzero(void)
{
    char    tab[10];

    ft_bzero(NULL, 0);
    memset(tab, 0xff, 10);
    ft_bzero(tab + 1, 8);
    if (0 != memcmp("\xff\0\0\0\0\0\0\0\0\xff", tab, 10))
        ERROR();
    return (1);
}
#endif

#ifdef TEST_MEMCPY
int     test_memcpy(void)
{
    char    tab[10];
    char    tab2[10];

    if (NULL != ft_memcpy(NULL, "a", 0))
        ERROR();
    memcpy(tab, "aaaaaaaaaa", 10);
    strcpy(tab2, "bbbbbbbb");
    if (tab + 1 != ft_memcpy(tab + 1, tab2, 8))
        ERROR();
    if (0 != memcmp("abbbbbbbba", tab, 10))
        ERROR();
    if (0 != strcmp(tab2, "bbbbbbbb"))
        ERROR();
    return (1);
}
#endif

#ifdef TEST_MEMCCPY
int     test_memccpy(void)
{
    char    tab[10];
    char    tab2[10];

    if (NULL != ft_memccpy(NULL, "a", 'a', 0))
        ERROR();
    if (NULL != ft_memccpy(tab, "aaaaaaaaaa", 'b', 10))
        ERROR();
    if (0 != memcmp(tab, "aaaaaaaaaa", 10))
        ERROR();
    if (NULL != ft_memccpy(tab + 1, "bbbbbbbbbb", 'a', 8))
        ERROR();
    if (0 != memcmp(tab, "abbbbbbbba", 10))
        ERROR();
    strcpy(tab2, "cccccee");
    if (tab + 8 != ft_memccpy(tab + 2, tab2, 'e', 7))
        ERROR();
    if (0 != memcmp(tab, "abccccceba", 10))
        ERROR();
    if (0 != strcmp(tab2, "cccccee"))
        ERROR();
    return (1);
}
#endif

#ifdef TEST_MEMMOVE
int     test_memmove(void)
{
    char    tab[10];
	int		i;
	char*	tab2;
    memcpy(tab, "abcdefghij", 10);
    if (tab + 5 != ft_memmove(tab + 5, tab + 4, 5))
        ERROR();
    if (0 != memcmp(tab, "abcdeefghi", 10))
        ERROR();
	tab2 = malloc(2000000);
	ft_memmove(tab2, tab2, 2000000);
	ft_memmove(tab, "abc\0efghij", 10);
	if (0 != memcmp(tab, "abc\0efghij", 10))
		ERROR();
    return (1);
}
#endif

#ifdef TEST_MEMCHR
int     test_memchr(void)
{
    char    tab[10];
    memcpy(tab, "abcdefghij", 10);

    if (NULL != ft_memchr(tab, 'k' | 0xff00, 10))
        ERROR();
    if (tab + 0 != ft_memchr(tab, 'a' | 0xff00, 10))
        ERROR();
    if (tab + 9 != ft_memchr(tab, 'j' | 0xff00, 10))
        ERROR();
    if (0 != memcmp(tab, "abcdefghij", 10))
        ERROR();
    return (1);
}
#endif

#ifdef TEST_MEMCMP
int     test_memcmp(void)
{
    char    tab1[5];
    char    tab2[5];

    if (0 != ft_memcmp("abcdefghij", "abcdefghij", 10))
        ERROR();
    if (0 != ft_memcmp("abcdefghijK", "abcdefghijR", 10))
        ERROR();
    if (0 == ft_memcmp("abcdefghij", "abcdefghik", 10))
        ERROR();
    if (0 <= ft_memcmp("abcd", "abcz", 4))
        ERROR();
    if (0 >= ft_memcmp("abz", "abc", 3))
        ERROR();
    if (0 >= ft_memcmp("zab", "aab", 3))
        ERROR();
    if (0 != ft_memcmp(NULL, NULL, 0))
        ERROR();
	if (0 != ft_memcmp("", "", 1))
		ERROR();
	if (0 >= ft_memcmp("\200", "\0", 1))
		ERROR();

    strcpy(tab1, "abcd");
    strcpy(tab2, "abde");
    ft_memcmp(tab1, tab2, 5);
    if (0 != strcmp(tab1, "abcd") || 0 != strcmp(tab2, "abde"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRLEN
int     test_strlen(void)
{
    char    tab[3];

    if (0 != ft_strlen(""))
        ERROR();
    if (1 != ft_strlen("a"))
        ERROR();
    if (8 != ft_strlen("abc\r\n\b\t\v\0a"))
        ERROR();

    strcpy(tab, "ab");
    ft_strlen(tab);
    if (0 != strcmp(tab, "ab"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRDUP
int     test_strdup(void)
{
    char    tab[13];
    char    *p1;
    char    *p2;
    char    *p3;
    char    *p4;
    char    *p5;
    char    *p6;
    char    tab2[17];

    strcpy(tab, "123456789012");
    p1 = malloc(13);
    p2 = malloc(13);
    p3 = ft_strdup(tab);
    p4 = malloc(13);

    if (0 != memcmp(tab, p3, 13))
        ERROR();

    if (tab == p3)
        ERROR();

    strcpy(tab2, "1234567890123456");
    p5 = ft_strdup(tab2);
    p6 = malloc(16);
    strcpy(p6, "abcdef");
    if (0 != strcmp(tab2, "1234567890123456"))
        ERROR();

    if (16 < strlen(p5))
        ERROR();

    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);
    free(p6);

    return (1);
}
#endif

#ifdef TEST_STRCPY
int     test_strcpy(void)
{
    char    tab[10];
    char    tab2[10];

    memcpy(tab2, "abcdefghi", 10);

    tab[0] = 'a';
    ft_strcpy(tab, "");
    if (0 != strcmp(tab, ""))
        ERROR();

    tab[9] = 'a';
    if (tab != ft_strcpy(tab, tab2))
        ERROR();

    if (0 != strcmp(tab, "abcdefghi"))
        ERROR();

    if (0 != strcmp(tab2, "abcdefghi"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRNCPY
int     test_strncpy(void)
{
    char    tab1[10];
    char    tab2[10];
    char    tab3[10];
    strcpy(tab1, "abcdefghi");
    strcpy(tab2, "abcdefghi");

    if (NULL != ft_strncpy(NULL, "12", 0))
        ERROR();

    strncpy(tab1, "12", 0);
    if (tab2 != ft_strncpy(tab2, "12", 0))
        ERROR();

    if (0 != memcmp(tab1, tab2, 10))
        ERROR();

    strncpy(tab1, "12", 2);
    ft_strncpy(tab2, "12", 2);
    if (0 != memcmp(tab1, tab2, 10))
        ERROR();

    strncpy(tab1, "1234", 3);
    ft_strncpy(tab2, "1234", 3);
    if (0 != memcmp(tab1, tab2, 10))
        ERROR();

    strcpy(tab3, "1234");
    strncpy(tab1, tab3, 10);
    ft_strncpy(tab2, tab3, 10);
    if (0 != memcmp(tab1, tab2, 10))
        ERROR();
    if (0 != memcmp(tab3, "1234", 5))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRCAT
int     test_strcat(void)
{
    char    tab[5];
    char    tab2[5];

    tab[0] = 0;
    if (tab != ft_strcat(tab, ""))
        ERROR();
    if (0 != strcmp(tab, ""))
        ERROR();
    if (tab != ft_strcat(tab, "a"))
        ERROR();
    if (0 != strcmp(tab, "a"))
        ERROR();
    memcpy(tab2, "bc", 3);
    if (tab != ft_strcat(tab, tab2))
        ERROR();
    if (0 != memcmp(tab2, "bc", 3))
        ERROR();
    if (0 != strcmp(tab, "abc"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRNCAT
int     test_strncat(void)
{
    char    tab[10];
    char    tab2[1000000];
    size_t  i;

    strcpy(tab, "abcDEFGHI");
    tab[3] = 0;
    if (tab != ft_strncat(tab, "d", 0))
        ERROR();
    if (0 != memcmp(tab, "abc\0EFGHI", 10))
        ERROR();
    if (tab != ft_strncat(tab, "d", 1000000))
        ERROR();
    if (0 != memcmp(tab, "abcd\0FGHI", 10))
        ERROR();
    i = 0;
    while (i < 1000000)
    {
        tab2[i] = 'e';
        i++;
    }
    if (tab != ft_strncat(tab, tab2, 1))
        ERROR();
    if (0 != memcmp(tab2, "eeeee", 5))
        ERROR();
    if (0 != memcmp(tab, "abcde\0GHI", 10))
        ERROR();
    if (tab != ft_strncat(tab, "fg", 4))
        ERROR();
    if (0 != memcmp(tab, "abcdefg\0I", 10))
        ERROR();

    return (1);    
}
#endif

#ifdef TEST_STRLCAT
int     test_strlcat(void)
{
    char    tab[10];
    char    s[10];

    memcpy(tab, "ABCDEFGHIJ", 10);
    tab[0] = '\0';
    if (0 != ft_strlcat(tab, "", 5))
        ERROR();
    if (0 != memcmp(tab, "\0BCDEFGHIJ", 10))
        ERROR();
    if (1 != ft_strlcat(tab, "a", 5))
        ERROR();
    if (0 != memcmp(tab, "a\0CDEFGHIJ", 10))
        ERROR();
    if (3 != ft_strlcat(tab, "bc", 5))
        ERROR();
    if (0 != memcmp(tab, "abc\0EFGHIJ", 10))
        ERROR();
    if (10 != ft_strlcat(tab, "defghij", 4))
        ERROR();
    if (0 != memcmp(tab, "abc\0EFGHIJ", 10))
        ERROR();
    if (10 != ft_strlcat(tab, "defghij", 7))
        ERROR();
    if (0 != memcmp(tab, "abcdef\0HIJ", 10))
        ERROR();
    if (2 != ft_strlcat(tab, "g", 1))
        ERROR();
    if (0 != memcmp(tab, "abcdef\0HIJ", 10))
        ERROR();
    strcpy(s, "abc");
    ft_strlcat(tab, s, 10);
    if (0 != memcmp(s, "abc", 4))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRCHR
int     test_strchr(void)
{
    char    tab[10];

    strcpy(tab, "bonbons");
    if (tab != ft_strchr(tab, 'b'))
        ERROR();
    if (tab + 1 != ft_strchr(tab, 'o'))
        ERROR();
    if (tab + 6 != ft_strchr(tab, 's'))
        ERROR();
    if (tab + 7 != ft_strchr(tab, '\0'))
        ERROR();
    if (tab + 7 != ft_strchr(tab, '\0' | 0xff00))
        ERROR();
    if (NULL != ft_strchr(tab, 'a'))
        ERROR();
    if (tab + 2 != ft_strchr(tab, 'n' | 0xff00))
        ERROR();
    if (0 != memcmp(tab, "bonbons", 8))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRRCHR
int     test_strrchr(void)
{
    char    tab[10];

    strcpy(tab, "Bonbons");
    if (tab + 3 != ft_strrchr(tab, 'b'))
        ERROR();
    if (tab + 4 != ft_strrchr(tab, 'o'))
        ERROR();
    if (tab + 6 != ft_strrchr(tab, 's'))
        ERROR();
    if (tab + 7 != ft_strrchr(tab, '\0'))
        ERROR();
    if (tab + 7 != ft_strrchr(tab, '\0' | 0xff00))
        ERROR();
    if (NULL != ft_strrchr(tab, 'a'))
        ERROR();
    if (tab + 5 != ft_strrchr(tab, 'n' | 0xff00))
        ERROR();
    if (tab != ft_strrchr(tab, 'B'))
        ERROR();
    if (0 != memcmp(tab, "Bonbons", 8))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRSTR
int     test_strstr(void)
{
    char    tab[21];
    size_t  i;
    char    tab2[1000000];

    strcpy(tab, "Aabcdefghiabcdefghij");
    if (tab != ft_strstr(tab, "A"))
        ERROR();
    if (tab + 1 != ft_strstr(tab, "a"))
        ERROR();
    if (tab + 19 != ft_strstr(tab, "j"))
        ERROR();
    if (tab != ft_strstr(tab, "Aa"))
        ERROR();
    if (tab + 17 != ft_strstr(tab, "hij"))
        ERROR();
    if (NULL != ft_strstr(tab, "n"))
        ERROR();
    if (NULL != ft_strstr(tab, "adef"))
        ERROR();
    if (NULL != ft_strstr(tab, "defa"))
        ERROR();
    if (tab != ft_strstr(tab, ""))
        ERROR();
    if (NULL != ft_strstr(tab + 1, "Aabc"))
        ERROR();
    if (tab != ft_strstr(tab, "Aabcdefghiabcdefghij"))
        ERROR();
    if (NULL != ft_strstr(tab, "Aabcdefghiabcdefghijk"))
        ERROR();
    if (0 != memcmp(tab, "Aabcdefghiabcdefghij", 20))
        ERROR();
	tab[0] = '\0';
	if (NULL != ft_strstr(tab, "abcdef"))
		ERROR();
	if (tab != ft_strstr(tab, ""))
		ERROR();


    i = 0;
    while (i < 1000000)
    {
        tab2[i] = 'a';
        i++;
    }
    tab2[20] = '\0';
    memcpy(tab2, "Aabcdefghiabcdefghij", 20);
    if (NULL != ft_strstr(tab, tab2))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRNSTR
int     test_strnstr(void)
{ 
    char    tab[21];

    strcpy(tab, "Aabcdefghiabcdefghij");
    if (tab != ft_strnstr(tab, "A", 2))
        ERROR();
    if (tab + 1 != ft_strnstr(tab, "a", 20))
        ERROR();
    if (NULL != ft_strnstr(tab, "j", 19))
        ERROR();
    if (tab + 19 != ft_strnstr(tab, "j", 20))
        ERROR();
    if (tab != ft_strnstr(tab, "Aa", 2))
        ERROR();
    if (tab + 17 != ft_strnstr(tab, "hij", 20))
        ERROR();
    if (NULL != ft_strnstr(tab, "hij", 19))
        ERROR();
    if (NULL != ft_strnstr(tab, "n", 1000000))
        ERROR();
    if (NULL != ft_strnstr(tab, "adef", 18))
        ERROR();
    if (NULL != ft_strnstr(tab, "defa", 20))
        ERROR();
    if (tab != ft_strnstr(tab, "", 25))
        ERROR();
    if (NULL != ft_strnstr(tab + 1, "Aabc", 10))
        ERROR();
    if (NULL != ft_strnstr(tab, "Aabcdefghiabcdefghij", 19))
        ERROR();
    if (tab != ft_strnstr(tab, "Aabcdefghiabcdefghij", 20))
        ERROR();
    if (0 != memcmp(tab, "Aabcdefghiabcdefghij", 20))
        ERROR();

    char    tab2[1000000];
    size_t  i = 0;
    while (i < 1000000)
    {
        tab2[i] = 'a';
        i++;
    }
    tab2[999999] = '\0';
    if (NULL != ft_strnstr(tab, tab2, 2000000))
        ERROR();


    return (1);
}
#endif

#ifdef TEST_STRCMP
int     test_strcmp(void)
{
    char    tab1[10];
    char    tab2[10];

    if (0 != ft_strcmp("", ""))
        ERROR();
    if (0 != ft_strcmp("a", "a"))
        ERROR();
    if (0 <= ft_strcmp("", "a"))
        ERROR();
    if (0 >= ft_strcmp("a", ""))
        ERROR();
    if (0 <= ft_strcmp("a", "b"))
        ERROR();
    if (0 >= ft_strcmp("b", "a"))
        ERROR();
    if (0 != ft_strcmp("ab", "ab"))
        ERROR();
    if (0 != ft_strcmp("abc", "abc"))
        ERROR();
    if (0 <= ft_strcmp("abc", "abd"))
        ERROR();
    if (0 <= ft_strcmp("abc", "bbc"))
        ERROR();
    if (0 >= ft_strcmp("bbc", "abd"))
        ERROR();
    if (0 >= ft_strcmp("abd", "abc"))
        ERROR();
    if (0 >= ft_strcmp("abcd", "abc"))
        ERROR();
    if (0 <= ft_strcmp("abc", "abcd"))
        ERROR();
	if (0 >= ft_strcmp("\200", "\0"))
		ERROR();

    strcpy(tab1, "abcd");
    strcpy(tab2, "abce");
    ft_strcmp(tab1, tab2);
    if (0 != strcmp(tab1, "abcd"))
        ERROR();
    if (0 != strcmp(tab2, "abce"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_STRNCMP
int     test_strncmp(void)
{
    char    tab1[10];
    char    tab2[10];

    if (0 != ft_strncmp("", "", 1000000))
        ERROR();
    if (0 != ft_strncmp("a", "a", 1000000))
        ERROR();
    if (0 <= ft_strncmp("", "a", 1000000))
        ERROR();
    if (0 == ft_strncmp("a", "", 1000000))
        ERROR();
    if (0 <= ft_strncmp("a", "b", 1000000))
        ERROR();
    if (0 >= ft_strncmp("b", "a", 1000000))
        ERROR();
    if (0 != ft_strncmp("ab", "ab", 1000000))
        ERROR();
    if (0 != ft_strncmp("abc", "abc", 1000000))
        ERROR();
    if (0 <= ft_strncmp("abc", "abd", 1000000))
        ERROR();
    if (0 <= ft_strncmp("abc", "bbc", 1000000))
        ERROR();
    if (0 >= ft_strncmp("bbc", "abd", 1000000))
        ERROR();
    if (0 >= ft_strncmp("abd", "abc", 1000000))
        ERROR();
    if (0 >= ft_strncmp("abcd", "abc", 1000000))
        ERROR();
    if (0 <= ft_strncmp("abc", "abcd", 1000000))
        ERROR();

    if (0 <= ft_strncmp("abc", "abcd", 4))
        ERROR();
    if (0 >= ft_strncmp("abcd", "abc", 4))
        ERROR();
    if (0 != ft_strncmp("abc", "abcd", 3))
        ERROR();
    if (0 != ft_strncmp("abcd", "abc", 3))
        ERROR();

    if (0 <= ft_strncmp("", "a", 1))
        ERROR();
    if (0 >= ft_strncmp("a", "", 1))
        ERROR();

    if (0 != ft_strncmp("", "a", 0))
        ERROR();
    if (0 != ft_strncmp("a", "", 0))
        ERROR();
	if (0 >= ft_strncmp("\200", "\0", 1))
		ERROR();

    strcpy(tab1, "abcd");
    strcpy(tab2, "abce");
    ft_strncmp(tab1, tab2, 1000000);
    if (0 != strcmp(tab1, "abcd"))
        ERROR();
    if (0 != strcmp(tab2, "abce"))
        ERROR();

    return (1);
}
#endif

#ifdef TEST_ATOI
int     test_atoi(void)
{
    if (ft_atoi("1") != atoi("1"))
        ERROR();
    if (ft_atoi("9") != atoi("9"))
        ERROR();
    if (ft_atoi("0") != atoi("0"))
        ERROR();
    if (ft_atoi("-0") != atoi("-0"))
        ERROR();
    if (ft_atoi("+1") != atoi("+1"))
        ERROR();
    if (ft_atoi("+12 ") != atoi("+12 "))
        ERROR();
    if (ft_atoi("\t23") != atoi("\t23"))
        ERROR();
    if (ft_atoi("+ 34") != atoi("+ 34"))
        ERROR();
    if (ft_atoi("- 45") != atoi("- 45"))
        ERROR();
    if (ft_atoi("-2147483648") != atoi("-2147483648"))
        ERROR();
    if (ft_atoi("2147483647") != atoi("2147483647"))
        ERROR();
    if (ft_atoi("+-21") != atoi("+-21"))
        ERROR();
    if (ft_atoi("-+23") != atoi("-+23"))
        ERROR();
    if (ft_atoi("-a+24") != atoi("-a+24"))
        ERROR();
    if (ft_atoi("\r+23a") != atoi("\r+23a"))
        ERROR();
    if (ft_atoi("2 3-b") != atoi("2 3-b"))
        ERROR();
    if (ft_atoi("0x10") != atoi("0x10"))
        ERROR();
    if (ft_atoi("a") != atoi("a"))
        ERROR();
    if (ft_atoi("\t\f\v\r\n 18\t\f\v\r\n") != atoi("\t\f\v\r\n 18\t\f\v\r\n"))
        ERROR();
    if (ft_atoi("- 19") != atoi("- 19"))
        ERROR();
    if (ft_atoi("090") != atoi("090"))
        ERROR();
    if (ft_atoi("-026") != atoi("-026"))
        ERROR();
    if (ft_atoi("a2") != atoi("a2"))
        ERROR();
    if (ft_atoi("\a26") != atoi("\a26"))
        ERROR();

    return (1);
}
#endif

#ifdef  TEST_ISALPHA
int     test_isalpha(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if ((0 == ft_isalpha(i) && 0 != isalpha(i))
         || (0 != ft_isalpha(i) && 0 == isalpha(i)))    {
            printf("'%c', ", i); ERROR();
        }
        i++;
    }
    return (1);    
}
#endif

#ifdef  TEST_ISDIGIT
int     test_isdigit(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if ((0 == ft_isdigit(i) && 0 != isdigit(i))
         || (0 != ft_isdigit(i) && 0 == isdigit(i)))    {
            printf("'%c', ", i); ERROR();
        }
        i++;
    }
    
    return (1);
}
#endif

#ifdef  TEST_ISALNUM
int     test_isalnum(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if ((0 == ft_isalnum(i) && 0 != isalnum(i))
         || (0 != ft_isalnum(i) && 0 == isalnum(i)))    {
            printf("'%c', ", i); ERROR();
        }
        i++;
    }
    
    return (1);
}
#endif

#ifdef  TEST_ISASCII
int     test_isascii(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if ((0 == ft_isascii(i) && 0 != isascii(i))
         || (0 != ft_isascii(i) && 0 == isascii(i)))    {
            printf("0x%08x, ", i); ERROR();
        }
        i++;
    }
    
    return (1);
}
#endif

#ifdef  TEST_ISPRINT
int     test_isprint(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if ((0 == ft_isprint(i) && 0 != isprint(i))
         || (0 != ft_isprint(i) && 0 == isprint(i)))    {
            printf("'%c', ", i); ERROR();
        }
        i++;
    }
    
    return (1);
}
#endif

#ifdef  TEST_TOUPPER
int     test_toupper(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if (ft_toupper(i) != toupper(i))    {
            printf("'%c', ", i); ERROR();
        }
        i++;
    }
    
    return (1);
}
#endif

#ifdef  TEST_TOLOWER
int     test_tolower(void)
{
    int     i;

    i = 0;
    while (i <= 0x7f)
    {
        if (ft_tolower(i) != tolower(i))    {
            printf("'%c', ", i); ERROR();
        }
        i++;
    }
    
    return (1);
}
#endif

#ifdef	TEST_PUTS
int     test_puts(void)
{
	int		out;
	int		p[2];
	char	sortie[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (ft_puts("abc") == EOF)
	{
		dup2(out, 1);
		ERROR();
	}

	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "abc\n"))
	{
		dup2(out, 1);
		ERROR();
	}

	dup2(out, 1);
	return (1);
}
#endif

#ifdef	TEST_CAT
int     test_cat(void)
{
	int		out;
	int		pipe_ft_cat[2];
	char	sortie_ft_cat[1024*1024];
	char	sortie_cat[1024*1024];
	int		fd_ft_cat;
	FILE	*fd_cat;

	out = dup(1);
	pipe(pipe_ft_cat);
	dup2(pipe_ft_cat[1], 1);

	// Lecture du fichier ft_cat.s avec ft_cat
	fd_ft_cat = open("srcs/ft_cat.s", O_RDONLY);
	if (fd_ft_cat < 0)
	{
		dup2(out, 1);
		ERROR();
	}
	ft_cat(fd_ft_cat);
	sortie_ft_cat[read(pipe_ft_cat[0], sortie_ft_cat, 1024*1024)] = '\0';

	// Lecture du fichier ft_cat.s avec le cat du systeme
	fd_cat = popen("cat srcs/ft_cat.s", "r");
	if (fd_cat == NULL)
	{
		dup2(out, 1);
		ERROR();
	}
	sortie_cat[fread(sortie_cat, 1, 1024*1024, fd_cat)] = '\0';

	// Comparaison de la sortie de ft_cat avec celle de la sortie de cat
	if (0 != strcmp(sortie_ft_cat, sortie_cat))
	{
		dup2(out, 1);
		ERROR();
	}

	// Fermeture des descripteurs de fichier
	close(fd_ft_cat);
	pclose(fd_cat);

	dup2(out, 1);

	ft_cat(-1);	// Ne doit pas planter
	ft_cat(fd_ft_cat); // Ne doit pas planter

	// Decommenter pour afficher la sortie standard de ft_cat
	//puts(sortie_ft_cat);
	
	return (1);
}
#endif

#ifdef TEST_PUTCHAR
int     test_putchar(void)
{
	int		out;
	int		p[2];
	char	sortie[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	ft_putchar('a');
	ft_putchar('b');
	sortie[read(p[0], sortie, 100)] = '\0';
	if (0 != strcmp(sortie, "ab"))
	{
		dup2(out, 1);
		ERROR();
	}

	dup2(out, 1);
	return (1);
}
#endif
