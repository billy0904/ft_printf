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

int	format_check(char c, int *i)
{
	if (c == 'c')
		return (0);
	else if (c == 's')
		return (0);
	else if (c == 'p')
		return (0);
	else if (c == 'd')
		return (0);
	else if (c == 'i')
		return (0);
	else if (c == 'u')
		return (0);
	else if (c == 'x')
		return (0);
	else if (c == 'X')
		return (0);
	else if (c == '%')
		return (0);
	return (0);
}

int	ft_printf(const char *format, ...)
{
}
