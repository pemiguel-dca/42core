/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:45:43 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/21 19:41:02 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TIRAR AS 25 LINHAS, usar as bases que tens no printf.h
int	do_hex(int n, char c) //char c aqui e para ver se e com o 'x' 'X'
{
	static int	len; //para ficar com o tamanho do numero

	if (!len)
		len = 0;
	if (c == 'x')
	{
		if (n > 15)
		{
			do_hex(n / 16, c);
			do_hex(n % 16, c);
		}
		else
		{
			len++;
			ft_putchar("0123456789abcdef"[n]);
		}
	}
	else if (c == 'X')
	{
		if (n > 15)
		{
			do_hex(n / 16, c);
			do_hex(n % 16, c);
		}
		else
		{
			len++;
			ft_putchar("0123456789ABCDEF"[n]);
		}
	}
	return (len);
}
