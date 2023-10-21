/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:57:58 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/21 14:51:12 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	count;
	
	count = 0;
	while (*str != '\0')
	{
		ft_print_char((int)*str);
		str++;
		count++;
	}
	return (count);
}

int	ft_print_digit(long n, int base)
{
	int	count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base), + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count += ft_print_digit(n / base, base);
		return (count += ft_print_digit(n % base, base));
	}
}

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1 ,format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int	main()
{
	ft_printf("meu nome e %s eu tenho %d anos", "pedro", 29);
}