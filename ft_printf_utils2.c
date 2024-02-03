/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:53:37 by gablee            #+#    #+#             */
/*   Updated: 2023/12/09 13:53:41 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	howlong(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	putnbr_hex(unsigned long long n, char *base, int *err)
{
	if (n >= 16)
		putnbr_hex((n / 16), base, err);
	if (*err == -1)
		return ;
	print_c(base[n % 16], err);
}

int	print_p(unsigned long long n, int *err)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n == 0)
		return (print_s("0x0", err));
	print_s("0x", err);
	if (*err == -1)
		return (-1);
	putnbr_hex(n, base, err);
	len = howlong(n) + 2;
	return (len);
}

int	print_x(unsigned int n, int *err)
{
	char			*base;
	unsigned int	len;

	base = "0123456789abcdef";
	len = 0;
	putnbr_hex((unsigned int)n, base, err);
	len = howlong((unsigned int)n);
	return (len);
}

int	print_ux(unsigned int n, int *err)
{
	char			*base;
	unsigned int	len;

	base = "0123456789ABCDEF";
	len = 0;
	putnbr_hex((unsigned int)n, base, err);
	len = howlong((unsigned int)n);
	return (len);
}
