/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:18:30 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/26 15:31:36 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list ap)
{
	if (*format == 'c')
		return(ft_putchar(va_arg(ap, int)));
	if(*format == 's')
		return(ft_putstr(va_arg(ap, char *)));
	if (*format == 'p')
		return(ft_ptr(va_arg(ap, void *), "0123456789abcdef"));
 	/*	if (*format == 'i')
	 */	
	return (0);
}