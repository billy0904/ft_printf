#include "ft_printf.c"
#include "ft_printf_utils.c"
#include "ft_printf_utils2.c"
#include <stdio.h>

int main()
{
	char *c = "%%%%%d%s%u%%%%%%%";
	ft_printf(c, 2147483649, "gablee", -100);
	printf("\n");
	printf(c, 2147483649, "gablee", -100);
}
