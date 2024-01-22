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

ssize_t	print_u(char u, int *i)
{
	unsigned int	n;
	unsigned int	a;
	int				len;

	n = (unsigned int) u;
	a = n;
	len = 0;
	if (a == 0)
		len = 1;
	while (a != 0)
	{
		a /= 10;
		len++;
	}
	ft_putnbr(n);
	return (len);
}

ssize_t	print_x(int n)
{
}

ssize_t	print_ux(int n, char c)
{
}

ssize_t	print_pc(char pc)
{
}
