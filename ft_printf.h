/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:51:02 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/26 15:18:42 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define	FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
# include <stdlib.h>

int				ft_printf(const char *format, ...);
int             ft_putchar(int c);
int             ft_putstr(char *str);
int             ft_ptr(void *nbr, char *base);
int				ft_format(const char *format, va_list ap);
char			*hex_to_str(unsigned long n, char *base);


#endif