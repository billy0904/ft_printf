#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	// char c;
	// c = 'c';
	// printf("%c\n", c);
	// ft_printf("%c\n", c);
	// printf("%s\n", "asdf");
	// ft_printf("%s\n", "asdf");
	// printf("%p\n", "asdf");
	// ft_printf("%p\n", "asdf");
	// printf("%d\n", 42);
	// ft_printf("%d\n", 42);
	// printf("%i\n", 4242);
	// ft_printf("%i\n", 4242);
	// printf("%u\n", 2147483649);
	// ft_printf("%u\n", 2147483649);
	// printf("%x\n", 43);
	// ft_printf("%x\n", 43);
	// printf("%X\n", 43);
	// ft_printf("%X\n", 43);
	// printf("%%\n");
	// ft_printf("%%\n");
	// printf("\n");
	// ft_printf("%d\n", -2147483648);
	// printf("%d\n", -2147483648);
	// ft_printf("%d\n", 0);
	// printf("%d\n", 0);
	// ft_printf("%s\n", "");
	// printf("%s\n", "");
	// ft_printf("%s\n", NULL);
	// printf("%s\n", NULL);

	ft_printf("I'll go home at %dpm\n", 9);
	printf("I'll go home at %dpm\n", 9);
	ft_printf("I'll go %s at %dpm\n", "home", 9);
	printf("I'll go %s at %dpm\n", "home", 9);
	ft_printf("%d%d%d%d%d\n", 12, 34, 56, 78, 9);


	return (0);
}
