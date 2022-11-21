/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:31:00 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/21 19:41:09 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static char	*ft_zero(int n, char *str)
{
	if (n == 0)
		str = ft_strdup("0");
	return (str);
}

static int	ft_size_char(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_size_char(n);
	str = malloc(i * sizeof(char) + 1);
	str[i--] = '\0';
	if (n == -2147483648)
	{
		n = -214748364;
		str[i--] = '8';
	}
	str = ft_zero(n, str);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
*/
static int	ft_check_white_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	atoi;

	i = ft_check_white_spaces((char *)str);
	atoi = 0;
	signal = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	return (atoi * signal);
}

void    ft_putstr(char *str)
{
	size_t  i;

	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1); // retorna 1 porque cada vez que a funcao e executada e para dar write a UM caracter
}

size_t	ft_putnbr(size_t n)
{
	int	len_n;

	if (!len_n)
		len_n = 1;
	if (n == MIN_INT)
	{
		ft_putchar('8');
		n = 214748364;
	}
	else if (n < 0)
		n = -n;
	else if (n > 9)
	{
		len_n++; //cada ve que o numero vem aqui adiciona a length para saber qual o seu tamanho total
		ft_putnbr(n % 10);
		ft_putnbr(n / 10);
	}
	ft_putchar(n + 48); // verificar se o mais 48 está certo
	return (0); //mudar para a len de n
}
