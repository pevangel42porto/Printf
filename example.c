/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:08:10 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/24 17:08:20 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	size;
	
	size = 0;
	while (*str != '\0')
	{
		ft_print_char((int)*str);
		str++;
		size++;
	}
	return (size);
}

int	ft_print_digit(long n, int base)
{
	int	size;
	char	*symbols;

	symbols = "0123456789abcdef";
	size = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base), + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		size += ft_print_digit(n / base, base);
		return (size += ft_print_digit(n % base, base));
	}
}

int	ft_print_format(char format, va_list ap)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_print_char(va_arg(ap, int));
	else if (format == 's')
		size += ft_print_str(va_arg(ap, char *));
	else if (format == 'd')
		size += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (format == 'x')
		size += ft_print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		size += write(1, &format, 1);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int	size;
	va_list	ap;

	va_start(ap, format);
	size = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			size += ft_print_format(*(++format), ap);
		else
			size += write(1 ,format, 1);
		format++;
	}
	va_end(ap);
	return (size);
}

int	main()
{
	ft_printf("meu nome e %s eu tenho %d anos", "pedro", 29);
}
