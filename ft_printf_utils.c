/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:47:04 by gablee            #+#    #+#             */
/*   Updated: 2023/12/02 20:47:06 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c, int *err)
{
	if (write(1, &c, 1) < 0)
		*err = -1;
	return (1);
}

int	print_s(char *s, int *err)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (print_s("(null)", err));
	while (s[i])
	{
		print_c(s[i], err);
		if (*err == -1)
			return (-1);
		i++;
	}
	return (i);
}

static void	putnbr_dec(long n, int *err)
{
	if (n > 9)
		putnbr_dec(n / 10, err);
	if (*err == -1)
		return ;
	print_c(n % 10 + '0', err);
}

int	print_di(int n, int *err)
{
	long long	num;
	long long	tmp;
	int			len;

	num = (long long)n;
	tmp = num;
	len = 0;
	if (tmp == 0)
		len = 1;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	if (num < 0)
	{
		if (*err == -1)
			return (-1);
		print_c('-', err);
		num *= -1;
		len += 1;
	}
	putnbr_dec(num, err);
	return (len);
}

int	print_u(char u, int *err)
{
	unsigned int	num;
	unsigned int	tmp;
	int				len;

	num = (unsigned int) u;
	tmp = num;
	len = 0;
	if (tmp == 0)
		len = 1;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	putnbr_dec(num, err);
	return (len);
}
