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

int	format_check(char c, va_list ap)
{
	if (c == 'c')
		return (print_c(va_arg(ap, int)));
	else if (c == 's')
		return (print_s(va_arg(ap, char *)));
	else if (c == 'p')
		return (print_p(va_arg(ap, unsigned long long))); //unsigned long long
	else if (c == 'd' || c == 'i')
		return (print_d(va_arg(ap, int)));
	else if (c == 'u')
		return (print_u(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (print_x(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (print_ux(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (print_c('%'));
	return (0);
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
