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

int	format_check(char c, va_list ap, int *err)
{
	if (c == 'c')
		return (print_c(va_arg(ap, int), err));
	else if (c == 's')
		return (print_s(va_arg(ap, char *), err));
	else if (c == 'p')
		return (print_p(va_arg(ap, unsigned long long), err));
	else if (c == 'd' || c == 'i')
		return (print_di(va_arg(ap, int), err));
	else if (c == 'u')
		return (print_u(va_arg(ap, unsigned int), err));
	else if (c == 'x')
		return (print_x(va_arg(ap, unsigned int), err));
	else if (c == 'X')
		return (print_ux(va_arg(ap, unsigned int), err));
	else if (c == '%')
		return (print_c('%', err));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n;
	int		err;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	n = 0;
	err = 0;
	while (format[i])
	{
		if (err == -1)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			n += format_check(format[i], ap, &err);
			continue ;
		}
		else
			n += print_c(format[i], &err);
		i++;
	}
	va_end(ap);
	return (n);
}
