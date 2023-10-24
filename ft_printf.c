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

static int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

static int	ft_print_s(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
static int	ft_print_p(void	*ptr)
{
	
}

static int	ft_print_p(unsigned long ptr)
{
	int	size;
	
	size = 0;
	if(ptr)
	{
		size += ft_print_digit();	
	}
			
}
static int	ft_printformat(char *format, va_list ap)
{
	int	size;
	
	size = 0;
	if (format == 'c')
		size += ft_print_c(va_arg(ap, int));
	else if(format == 's')
		size += ft_print_s(va_arg(ap, int));
	else if (format == 'p')
		size += ft_
		
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