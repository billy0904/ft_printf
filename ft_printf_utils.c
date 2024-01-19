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

ssize_t	print_c(char c, int *e)
{
	if (write(1, &c, 1) < 0)
		*e = -1;
	return (1);
}

ssize_t	print_s(char *s, int *e)
{
	ssize_t	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			*e = -1;
		return (6);
	}
	while (s[i])
	{
		print_c(s[i], e);
		if (*e == -1)
			return (-1);
		i++;
	}
	return (i);
}

ssize_t	print_p(size_t n)
{
}

ssize_t	print_d(int d)
{
}

ssize_t	print_i(int i)
{
}
