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

int		format_check(char c, va_list ap, int *err);
int		ft_printf(const char *format, ...);
int		print_c(char c, int *err);
int		print_s(char *s, int *err);
int		print_p(unsigned long long n, int *err);
int		print_di(int d, int *err);
int		print_u(int u, int *err);
int		print_x(unsigned int n, int *err);
int		print_ux(unsigned int n, int *err);

#endif
