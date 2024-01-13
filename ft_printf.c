/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:46:52 by gablee            #+#    #+#             */
/*   Updated: 2023/12/02 20:46:54 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(char c, va_list ap, int *i)
{
	if (c == 'c')
		return (print_c((char)va_arg(ap, int), i));
	else if (c == 's')
		return (print_s((char)va_arg(ap, int), i));
	else if (c == 'p')
		return (print_p((char)va_arg(ap, int)));
	else if (c == 'd')
		return (print_d((char)va_arg(ap, int)));
	else if (c == 'i')
		return (print_i((char)va_arg(ap, int)));
	else if (c == 'u')
		return (print_u((char)va_arg(ap, int)));
	else if (c == 'x')
		return (print_x((char)va_arg(ap, int)));
	else if (c == 'X')
		return (print_ux((char)va_arg(ap, int)));
	else if (c == '%')
		return (print_pc((char)va_arg(ap, int)));
	return (0);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * -1;
		write (1, "-", 1);
		ft_putnbr (nb);
	}
	else if (nb < 10)
	{
		c = nb + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		n;
	int		err;

	i = 0;
	n = 0;
	err = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			n += format_check(format[i], ap, &i);
		}
		else if (err == -1)
			return (-1);
	}
	va_end(ap);
	return (n);
}
