/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:58 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/26 17:07:59 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	size;
	int	i;
	va_list	ap;
	
	va_start(ap, format);
	size = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_format((char *)&format[i], ap);
		}
		else
			size += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return(size);
}