/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:56:22 by gablee            #+#    #+#             */
/*   Updated: 2023/12/04 15:56:26 by gablee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		format_check(char c, va_list *ap, int e);
ssize_t	print_c(char c, int *e);
ssize_t	print_s(char *s, int *e);
ssize_t	print_p(size_t n);
ssize_t	print_d(int d);
ssize_t	print_i(int i);
ssize_t	print_x(int n);
ssize_t	print_ux(int n, char c);
int		ft_printf(const char *format, ...);

void	ft_putnbr(int nb);

#endif
