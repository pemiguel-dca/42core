/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:44:18 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/20 19:16:50 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return ((char *)(str + i));
}

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
/*
void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total;
	void	*ptr;

	total = nitems * size;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
*/