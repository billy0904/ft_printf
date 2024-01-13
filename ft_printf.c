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

int	format_check(char c, va_list *ap)
{
	if (c == 'c')
		return (print_c(va_arg(*ap, int)));
	else if (c == 's')
		return (print_s(va_arg(*ap, char *)));
	else if (c == 'p')
		return (print_p(va_arg(*ap, void *)));
	else if (c == 'd')
		return (print_d(va_arg(*ap, int)));
	else if (c == 'i')
		return (print_i(va_arg(*ap, int)));
	else if (c == 'u')
		return (print_u(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (print_x(va_arg(*ap, unsigned int)));
	else if (c == 'X')
		return (print_ux(va_arg(*ap, unsigned int), c));
	else if (c == '%')
		return (print_pc(va_arg(*ap, char), c));
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
