#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

static void assert(int condition)
{
	if (condition)
		printf("OK\n");
	else
		printf("Oh no.\n");
}

static void add_one(char *c)
{
	*c = *c + 1;
}

static void add_value(unsigned int i, char *c)
{
	*c = *c + i;
}

static char plus_one(char c)
{
	return c + 1;
}

static char plus_value(unsigned int i, char c)
{
	return c + i;
}

static void free_print(void *ptr, size_t size)
{
	printf("Freeing %zu bytes of memory.\n", size);
	free(ptr);
}

static void put_list_item(t_list *link)
{
	write(1, link->content, link->content_size);
}

static char upper(char c)
{
	return (char) ft_toupper(c);
}

static t_list *gobigger(t_list *link)
{
	t_list *newlink = malloc(sizeof(t_list));
	char *c = link->content;
	if (*c == 'l')
	{
		newlink->content = malloc(1 * sizeof(char));
		ft_memcpy(newlink->content, "!", 1);
		newlink->content_size = 1;
	}
	else if (*c == 'a')
	{
		newlink->content = malloc(6 * sizeof(char));
		ft_memcpy(newlink->content, "SPARTA", 6);
		newlink->content_size = 6;
}
	else
	{
		newlink->content = malloc(link->content_size * sizeof(void *));
		newlink->content = ft_strmap(link->content, &upper);
		newlink->content_size = link->content_size;
	}
	return newlink;
}

static void strlcat_test(const char *dst, const char *src, int n, char *str1, char *str2)
{
	ft_memcpy(str1, dst, 27);
	ft_memcpy(str2, dst, 27);
	int a = strlcat(str1, src, n);
	int b = ft_strlcat(str2, src, n);
	printf("%d\t%d\n", a, b);
	for (int i = 0; i < 20; i++)
	{
		if (*(str1 + i) == 0)
			write(1, "0", 1);
		else
			write(1, str1 + i, 1);
	}
	write(1, "\t", 1);
	for (int i = 0; i < 20; i++)
	{
		if (*(str2 + i) == 0)
			write(1, "0", 1);
		else
			write(1, str2 + i, 1);
	}
	write(1, "\n", 1);
}

int main()
{
	printf("ft_emset\n");
	char str1[100];
	char str2[100];
	str1[12] = 0;
	str2[12] = 0;
	memset(str1, 'a', 12);
	ft_memset(str2, 'a', 12);
	printf("%s\t%s\n", str1, str2);

	printf("ft_bzero\n");
	bzero(str1+4, 4);
	bzero(str1+2, 0);
	ft_bzero(str2+4, 4);
	ft_bzero(str2+2, 0);
	printf("%s\t%s\n", str1, str2);
	printf("%s\t%s\n", str1+8, str2+8);

	printf("ft_memcpy\n");
	const char str3[8] = "bcdcbax\0";
	memcpy(str1+1, str3, 6);
	ft_memcpy(str2+1, str3, 6);
	printf("%s\t%s\n", str1, str2);

	printf("ft_memccpy\n");
	memccpy(str1+7, str3, 'a', 42);
	ft_memccpy(str2+7, str3, 'a', 42);
	printf("%s\t%s\n", str1, str2);

	printf("ft_memmove\n");
	str1[4] = 0;
	str2[4] = 0;
	printf("%s\t%s\n", str1, str2);
	memmove(str1, str1+1, 3);
	ft_memmove(str2, str2+1, 3);
	printf("%s\t%s\n", str1, str2);
	memmove(str1+1, str1, 3);
	ft_memmove(str2+1, str2, 3);
	printf("%s\t%s\n", str1, str2);

	printf("ft_memchr\n");
	printf("%p\t%p\n", memchr(str1, 0, 42), ft_memchr(str1, 0, 42));
	printf("%p\t%p\n", memchr(str1, 'a', 42), ft_memchr(str1, 'a', 42));

	printf("ft_memcmp\n");
	printf("%d\t%d\n", memcmp("cat", "dog", 10), ft_memcmp("cat", "dog", 10));
	printf("%d\t%d\n", memcmp("piscine", "pisces", 6), ft_memcmp("piscine", "pisces", 6));
	printf("%d\t%d\n", memcmp("42.0", "420", 2), ft_memcmp("42.0", "420", 2));
	printf("%d\t%d\n", memcmp("cat", "dog", 0), ft_memcmp("cat", "dog", 0));

	printf("ft_strlen\n");
	printf("%lu\t%lu\n", strlen("42"), ft_strlen("42"));
	printf("%lu\t%lu\n", strlen(""), ft_strlen(""));
	printf("%lu\t%lu\n", strlen("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"), ft_strlen("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));

	printf("ft_strdup\n");
	char *str4 = strdup(str1);
	char *str5 = ft_strdup(str2);
	printf("%s\t%s\n", str4, str5);
	printf("%d\t%d\n", str4 == str1, str5 == str2);

	printf("ft_strcpy\n");
	strcpy(str4, str1+8);
	ft_strcpy(str5, str2+8);
	printf("%s\t%s\n", str4, str5);

	printf("ft_strncpy\n");
	strncpy(str4, str1, 2);
	ft_strncpy(str5, str2, 2);
	printf("%s\t%s\n", str4, str5);
	strncpy(str4+2, "X", 1);
	ft_strncpy(str5+2, "X", 1);
	printf("%s\t%s\n", str4, str5);
	strncpy(str4+2, "Y", 0);
	ft_strncpy(str5+2, "Y", 0);
	printf("%s\t%s\n", str4, str5);

	printf("ft_strcat\n");
	strcat(str1, str4);
	ft_strcat(str2, str5);
	printf("%s\t%s\n", str1, str2);

	printf("ft_strncat\n");
	strncat(str4, str1, 3);
	ft_strncat(str5, str2, 3);
	printf("%s\t%s\n", str4, str5);

	printf("ft_strlcat\n");
	strlcat(str1, str4, 15);
	strlcat(str2, str5, 15);
	printf("%s\t%s\n", str1, str2);

	printf("ft_strchr\n");
	printf("%p\t%p\n", strchr(str1, 'X'), ft_strchr(str1, 'X'));
	printf("%p\t%p\n", strchr(str1, 'a'), ft_strchr(str1, 'a'));
	printf("%p\t%p\n", strchr(str1, 'x'), ft_strchr(str1, 'x'));
	printf("%p\t%p\n", strchr(str1, 0), ft_strchr(str1, 0));

	printf("ft_strrchr\n");
	printf("%p\t%p\n", strrchr(str1, 'X'), ft_strrchr(str1, 'X'));
	printf("%p\t%p\n", strrchr(str1, 'a'), ft_strrchr(str1, 'a'));
	printf("%p\t%p\n", strrchr(str1, 'x'), ft_strrchr(str1, 'x'));
	printf("%p\t%p\n", strrchr(str1, 0), ft_strrchr(str1, 0));

	printf("ft_strstr\n");
	char str6[100] = "The quick brown fox jumps over the very, very, very lazy dog.\0 42";
	printf("%p\t%p\n", strstr(str6, "quick brown fox"), ft_strstr(str6, "quick brown fox"));
	printf("%p\t%p\n", strstr(str6, "42"), ft_strstr(str6, "42"));
	printf("%p\t%p\n", strstr(str6, "very, very lazy dog"), ft_strstr(str6, "very, very lazy dog"));
	printf("%p\t%p\n", strstr(str6, ""), ft_strstr(str6, ""));
	printf("%p\t%p\n", strstr(str6+62, ""), ft_strstr(str6+62, ""));

	printf("ft_strnstr\n");
	printf("%p\t%p\n", strnstr(str6, "quick brown fox", 19), ft_strnstr(str6, "quick brown fox", 19));
	printf("%p\t%p\n", strnstr(str6, "quick brown fox", 18), ft_strnstr(str6, "quick brown fox", 18));
	printf("%p\t%p\n", strnstr(str6, "42", 100), ft_strnstr(str6, "42", 100));
	printf("%p\t%p\n", strnstr(str6, "very, very lazy dog", 100), ft_strnstr(str6, "very, very lazy dog", 100));
	printf("%p\t%p\n", strnstr(str6, "", 42), ft_strnstr(str6, "", 42));
	printf("%p\t%p\n", strnstr(str6+62, "", 10), ft_strnstr(str6+62, "", 10));

	printf("ft_strcmp\n");
	printf("%d\t%d\n", strcmp("cat", "dog"), ft_strcmp("cat", "dog"));
	printf("%d\t%d\n", strcmp("cat", "cat"), ft_strcmp("cat", "cat"));
	printf("%d\t%d\n", strcmp("piscine", "pisces"), ft_strcmp("piscine", "pisces"));
	printf("%d\t%d\n", strcmp("", ""), ft_strcmp("", ""));

	printf("ft_strncmp\n");
	printf("%d\t%d\n", strncmp("cat", "dog", 10), ft_strncmp("cat", "dog", 10));
	printf("%d\t%d\n", strncmp("cat", "cat", 10), ft_strncmp("cat", "cat", 10));
	printf("%d\t%d\n", strncmp("piscine", "pisces", 6), ft_strncmp("piscine", "pisces", 6));
	printf("%d\t%d\n", strncmp("42.0", "420", 2), ft_strncmp("42.0", "420", 2));
	printf("%d\t%d\n", strncmp("cat", "dog", 0), ft_strncmp("cat", "dog", 0));

	printf("ft_atoi\n");
	printf("%d\t%d\n", atoi("+42"), ft_atoi("+42"));
	printf("%d\t%d\n", atoi("-42"), ft_atoi("-42"));
	printf("%d\t%d\n", atoi("++42"), ft_atoi("++42"));
	printf("%d\t%d\n", atoi("+-42"), ft_atoi("+-42"));
	printf("%d\t%d\n", atoi("-+42"), ft_atoi("-+42"));
	printf("%d\t%d\n", atoi("--42"), ft_atoi("--42"));
	printf("%d\t%d\n", atoi("+ 42"), ft_atoi("+ 42"));
	printf("%d\t%d\n", atoi("- 42"), ft_atoi("- 42"));
	printf("%d\t%d\n", atoi(" 42"), ft_atoi(" 42"));
	printf("%d\t%d\n", atoi(" +42"), ft_atoi(" +42"));
	printf("%d\t%d\n", atoi(" -42"), ft_atoi(" -42"));
	printf("%d\t%d\n", atoi("42b"), ft_atoi("42b"));
	printf("%d\t%d\n", atoi("b"), ft_atoi("b"));
	printf("%d\t%d\n", atoi("2147483647"), ft_atoi("2147483647"));
	printf("%d\t%d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("%d\t%d\n", atoi("-2147483647"), ft_atoi("-2147483647"));
	printf("%d\t%d\n", atoi("2147483649"), ft_atoi("2147483649"));
	printf("%d\t%d\n", atoi("9223372036854775800"), ft_atoi("9223372036854775800"));
	printf("%d\t%d\n", atoi("9223372036854775810"), ft_atoi("9223372036854775810"));

	printf("ft_isalpha\n");
	printf("%d\t%d\n", isalpha('a'), ft_isalpha('a'));
	printf("%d\t%d\n", isalpha('Z'), ft_isalpha('Z'));
	printf("%d\t%d\n", isalpha('1'), ft_isalpha('1'));
	printf("%d\t%d\n", isalpha('?'), ft_isalpha('?'));
	printf("%d\t%d\n", isalpha(1), ft_isalpha(1));

	printf("ft_isdigit\n");
	printf("%d\t%d\n", isdigit('a'), ft_isdigit('a'));
	printf("%d\t%d\n", isdigit('0'), ft_isdigit('0'));
	printf("%d\t%d\n", isdigit('9'), ft_isdigit('9'));
	printf("%d\t%d\n", isdigit('?'), ft_isdigit('?'));
	printf("%d\t%d\n", isdigit(1), ft_isdigit(1));

	printf("ft_isalnum\n");
	printf("%d\t%d\n", isalnum('z'), ft_isalnum('z'));
	printf("%d\t%d\n", isalnum('A'), ft_isalnum('A'));
	printf("%d\t%d\n", isalnum('0'), ft_isalnum('0'));
	printf("%d\t%d\n", isalnum('9'), ft_isalnum('9'));
	printf("%d\t%d\n", isalnum('?'), ft_isalnum('?'));
	printf("%d\t%d\n", isalnum(1), ft_isalnum(1));

	printf("ft_isascii\n");
	printf("%d\t%d\n", isascii('a'), ft_isascii('a'));
	printf("%d\t%d\n", isascii('1'), ft_isascii('1'));
	printf("%d\t%d\n", isascii('?'), ft_isascii('?'));
	printf("%d\t%d\n", isascii(1), ft_isascii(1));
	printf("%d\t%d\n", isascii(0), ft_isascii(0));
	printf("%d\t%d\n", isascii(0177), ft_isascii(0177));
	printf("%d\t%d\n", isascii(0200), ft_isascii(0200));

	printf("ft_isprint\n");
	printf("%d\t%d\n", isprint('a'), ft_isprint('a'));
	printf("%d\t%d\n", isprint('1'), ft_isprint('1'));
	printf("%d\t%d\n", isprint('?'), ft_isprint('?'));
	printf("%d\t%d\n", isprint('~'), ft_isprint('~'));
	printf("%d\t%d\n", isprint(' '), ft_isprint(' '));
	printf("%d\t%d\n", isprint(0177), ft_isprint(0177));
	printf("%d\t%d\n", isprint(037), ft_isprint(037));

	printf("ft_toupper\n");
	printf("%c\t%c\n", (char) toupper('a'), (char) toupper('a'));
	printf("%c\t%c\n", (char) toupper('z'), (char) toupper('z'));
	printf("%c\t%c\n", (char) toupper('M'), (char) toupper('M'));
	printf("%c\t%c\n", (char) toupper('6'), (char) toupper('6'));
	printf("%c\t%c\n", (char) toupper('`'), (char) toupper('`'));
	printf("%c\t%c\n", (char) toupper('{'), (char) toupper('{'));
	printf("%d\t%d\n", toupper(0), toupper(0));

	printf("ft_tolower\n");
	printf("%c\t%c\n", (char) tolower('A'), (char) ft_tolower('A'));
	printf("%c\t%c\n", (char) tolower('Z'), (char) ft_tolower('Z'));
	printf("%c\t%c\n", (char) tolower('m'), (char) ft_tolower('m'));
	printf("%c\t%c\n", (char) tolower('6'), (char) ft_tolower('6'));
	printf("%c\t%c\n", (char) tolower('@'), (char) ft_tolower('@'));
	printf("%c\t%c\n", (char) tolower('['), (char) ft_tolower('['));
	printf("%d\t%d\n", tolower(0), ft_tolower(0));


	printf("ft_strlcat\n");
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 11, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 10, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 9, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 6, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 5, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 4, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "ABCDE", 0, str1, str2);
	strlcat_test("abcde\0fghijklmnopqrstuvwxyz", "\0ABCDE", 15, str1, str2);
	strlcat_test("\0abcdefghijklmnopqrstuvwxyz", "ABCDE", 15, str1, str2);
	strlcat_test("\0abcdefghijklmnopqrstuvwxyz", "\0ABCDE", 15, str1, str2);





	printf("\n\n\nft_memdel\n");
	char *str7 = ft_memalloc(5);
	if (str7)
	{
		printf("%p\n", str7);
		for (int i = 0; i < 5; i++)
			assert(str7[i] == 0);

		void *str7v = str7;
		ft_memdel(&str7v);
		printf("%p\n", str7v);
		assert(str7v == 0);
	}

	printf("ft_strdel\n");
	str7 = ft_strnew(5);
	if (str7)
	{
		printf("%p\n", str7);
		for (int i = 0; i < 6; i++)
			assert(str7[i] == 0);

		ft_strdel(&str7);
		printf("%p\n", str7);
		assert(str7 == 0);
	}

	printf("ft_strclr\n");
	char str8[13] = "abcdefghijkl\0"; // Not gonna test for null cause lazy
	ft_strclr(str8);
	for (int i = 0; i < 12; i++)
		assert(str8[i] == 0);

	printf("ft_striter\n");
	strcpy(str8, "Gdkkn^vnqkc-");
	ft_striter(str8, &add_one);
	printf("-------------------------------------------\n");
	ft_striter(str8, NULL);
	ft_striter("", &add_one);
	printf("-------------------------------------------\n");
	printf("%s\n", str8);

	printf("ft_striteri\n");
	strcpy(str8, "HdjikZqhjcZ#");
	ft_striteri(str8, &add_value);
	printf("%s\n", str8);

	printf("ft_strmap\n");
	strcpy(str8, "Gdkkn^vnqkc-");
	char *str9 = ft_strmap(str8, &plus_one);
	printf("%s\n", str9);

	printf("ft_strmapi\n");
	free(str9);
	strcpy(str8, "HdjikZqhjcZ#");
	str9 = ft_strmapi(str8, &plus_value);
	printf("%s\n", str9);

	printf("ft_strequ\n");
	printf("cat, dog = %d\n", ft_strequ("cat", "dog"));
	printf("cat, cat = %d\n", ft_strequ("cat", "cat"));
	printf("piscine, pisces = %d\n", ft_strequ("piscine", "pisces"));
	printf(",  = %d\n", ft_strequ("", ""));

	printf("ft_strnequ\n");
	printf("cat, dog, 10 = %d\n", ft_strnequ("cat", "dog", 10));
	printf("cat, cat, 10 = %d\n", ft_strnequ("cat", "cat", 10));
	printf("piscine, pisces, 6 = %d\n", ft_strnequ("piscine", "pisces", 6));
	printf("42.0, 420, 2 = %d\n", ft_strnequ("42.0", "420", 2));
	printf("cat, dog, 0 = %d\n", ft_strnequ("cat", "dog", 0));

	printf("ft_strsub\n");
	char *str10 = ft_strsub("smiles", 1, 4);
	printf("%s\n", str10);
	free(str10);
	str10 = ft_strsub("hamburger", 4, 4);
	printf("%s\n", str10);
	free(str10);

	printf("ft_strjoin\n");
	str10 = ft_strjoin("4", "2");
	printf("%s.\n", str10);
	free(str10);
	str10 = ft_strjoin("", "42");
	printf("%s.\n", str10);
	free(str10);
	str10 = ft_strjoin("42", "");
	printf("%s.\n", str10);
	free(str10);

	printf("ft_strtrim\n");
	str10 = ft_strtrim(" \t\ntrim\tthis string\tplease\nthank you\n\t \t\n");
	printf("%s.\n", str10);
	free(str10);
	str10 = ft_strtrim("\tthis one too please ");
	printf("%s.\n", str10);
	free(str10);
	str10 = ft_strtrim("and one more");
	printf("%s.\n", str10);
	free(str10);

	printf("ft_strsplit\n");
	char **split = ft_strsplit("***a*ab***abc***", '*');
	printf("%p\n", split);
	assert(split[3] == 0);
	assert(ft_strequ(split[0], "a"));
	assert(ft_strequ(split[1], "ab"));
	assert(ft_strequ(split[2], "abc"));
	free(split);

	split = ft_strsplit("abc_bc_c", '_');
	printf("%p\n", split);
	assert(split[3] == 0);
	assert(ft_strequ(split[0], "abc"));
	assert(ft_strequ(split[1], "bc"));
	assert(ft_strequ(split[2], "c"));
	free(split);

	printf("ft_itoa\n");
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(9));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(11));
	printf("%s\n", ft_itoa(4242));
	printf("%s\n", ft_itoa(9001));
	printf("%s\n", ft_itoa(0x7fffffff));
	printf("%s\n", ft_itoa(0x80000000));
	printf("%s\n", ft_itoa(0x80000001));
	printf("%s\n", ft_itoa(-9001));
	printf("%s\n", ft_itoa(-4242));
	printf("%s\n", ft_itoa(-11));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(-9));
	printf("%s\n", ft_itoa(-1));

	printf("ft_putchar\n");
	ft_putchar('H');
	ft_putchar('e');
	ft_putchar('l');
	ft_putchar('l');
	ft_putchar('o');
	ft_putchar(' ');
	ft_putchar('w');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('l');
	ft_putchar('d');
	ft_putchar('!');
	ft_putchar('\n');

	printf("ft_putstr\n");
	ft_putstr("Hello world!\n");
	ft_putstr("\xE3\x8B\xA1\n\0");

	printf("ft_putendl\n");
	ft_putendl("Hello world!");

	printf("ft_putnbr\n");
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(1);
	ft_putchar('\n');
	ft_putnbr(9);
	ft_putchar('\n');
	ft_putnbr(10);
	ft_putchar('\n');
	ft_putnbr(11);
	ft_putchar('\n');
	ft_putnbr(4242);
	ft_putchar('\n');
	ft_putnbr(9001);
	ft_putchar('\n');
	ft_putnbr(0x7fffffff);
	ft_putchar('\n');
	ft_putnbr(0x80000000);
	ft_putchar('\n');
	ft_putnbr(0x80000001);
	ft_putchar('\n');
	ft_putnbr(-9001);
	ft_putchar('\n');
	ft_putnbr(-4242);
	ft_putchar('\n');
	ft_putnbr(-11);
	ft_putchar('\n');
	ft_putnbr(-10);
	ft_putchar('\n');
	ft_putnbr(-9);
	ft_putchar('\n');
	ft_putnbr(-1);
	ft_putchar('\n');

	printf("fd\n");
	int fd = open("temp.txt", O_RDWR);
	if (fd != 0)
	{
		ft_putchar_fd('H', fd);
		ft_putchar_fd('e', fd);
		ft_putchar_fd('l', fd);
		ft_putchar_fd('l', fd);
		ft_putchar_fd('o', fd);
		ft_putchar_fd(' ', fd);
		ft_putchar_fd('w', fd);
		ft_putchar_fd('o', fd);
		ft_putchar_fd('r', fd);
		ft_putchar_fd('l', fd);
		ft_putchar_fd('d', fd);
		ft_putchar_fd('!', fd);
		ft_putchar_fd('\n', fd);

		ft_putstr_fd("Hello world!\n", fd);
		ft_putstr_fd("\xE3\x8B\xA1\n\0", fd);

		ft_putendl_fd("Hello world!", fd);

		ft_putnbr_fd(0, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(1, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(9, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(10, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(11, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(4242, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(9001, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(0x7fffffff, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(0x80000000, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(0x80000001, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-9001, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-4242, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-11, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-10, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-9, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-1, fd);
		ft_putchar_fd('\n', fd);

		close(fd);
	}

	printf("ft_lstnew\n");
	char content1[6] = "Hello\0";
	t_list *link1 = ft_lstnew(content1, 6);
	assert(link1->content != content1);
	assert(ft_strequ(link1->content, "Hello\0"));
	assert(link1->content_size == 6);
	assert(link1->next == NULL);

	int content2 = 42;
	t_list *link2 = ft_lstnew(&content2, 4);
	assert( *((int*) link2->content) == 42);
	assert(link2->content_size == 4);

	t_list *link3 = ft_lstnew(NULL, 42);
	assert(link3->content == NULL);
	assert(link3->content_size == 0);

	printf("ft_lstadd\n");
	t_list *list = link3;
	ft_lstadd(&list, link2);
	ft_lstadd(&list, link1);
	assert(ft_strequ(link1->content, "Hello\0"));
	assert(list == link1);
	assert(list->next == link2);
	assert(list->next->next == link3);

	printf("ft_lstdelone\n");
	ft_lstdelone(&(list->next->next), &free_print);
	assert(list == link1);
	assert(list->next == link2);
	assert(list->next->next == NULL);

	printf("ft_lstdel\n");
	ft_lstdel(&list, &free_print);
	assert(list == NULL);

	printf("ft_lstiter\n");
	list = ft_lstnew("list.", 5);
	ft_lstadd(&list, ft_lstnew("linked ", 7));
	ft_lstadd(&list, ft_lstnew("a ", 2));
	ft_lstadd(&list, ft_lstnew("is ", 3));
	ft_lstadd(&list, ft_lstnew("This ", 5));
	ft_lstiter(list, &put_list_item);
	write(1, "\n", 1);

	printf("ft_lstmap\n");
	t_list *list2 = ft_lstmap(list, &gobigger);
	ft_lstiter(list2, &put_list_item);
	write(1, "\n", 1);

	return 0;
}

