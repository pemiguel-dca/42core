/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:27 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/22 20:20:08 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(va_list args, char c)
{
	int	total_length;

	total_length = 0;
	if (c == 's')
		total_length += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		total_length += ft_putchar(va_arg(args, int));
	else if (c == 'd')
		total_length += ft_putnbr_dec(va_arg(args, int));
	else if (c == 'i')
		total_length += ft_putnbr_dec(va_arg(args, int));
	else if (c == 'p')
		total_length += do_pointer(va_arg(args, size_t));
	else if (c == 'x')
		total_length += do_hex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		total_length += do_hex(va_arg(args, unsigned int), c);
	else if (c == 'u')
		total_length += ft_putnbr(va_arg(args, unsigned int));
	else if (c == '%')
		total_length += ft_putchar('%');
	return (total_length);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	int		total_length;

	va_start(args, format);
	i = 0;
	total_length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			total_length += print(args, format[i]);
		}
		else
			total_length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total_length);
}
