/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:51:02 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/21 14:46:05 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define	FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int				ft_printf(const char *format, ...);
int             ft_printf_c(int c);
int             ft_printf_s(char *str);
int             ft_printf_p(unsigned int ptr, va_list);

#endif