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
#define FT_PRINTF_H

#include <unistd.h>

int format_check(char c, int *i);
ssize_t print_c(va_list **n);
ssize_t print_s(va_list **n);
ssize_t print_p(va_list **n);
ssize_t print_d(va_list **n);
ssize_t print_i(va_list **n);
ssize_t print_x(va_list **n);
ssize_t print_ux(va_list **n);
int ft_printf(const char *format, ...);

#endif
