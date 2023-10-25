/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:58 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/24 17:58:53 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	ft_printformat(char *format, va_list ap)
{
	int	size;
	
	size = 0;
	if (format == 'c')
		size += ft_print_c(va_arg(ap, int));
	else if(format == 's')
		size += ft_print_s(va_arg(ap, int));
	else if (format == 'p')
		size += ft_printf_p(va_arg(ap, unsigned int));
		
}
int	ft_printf(char *format, ...)
{
	int	size;
	va_list	ap;
	
	va_start(ap, format);
	size = 0;
	while (*format != '\0')
	{
		if (format == '%')
			size += ft_printformat(format++, ap);
		else
			size += write(1, &format, 1);
		format++;
	}
	va_end(ap);
	return(size);
}