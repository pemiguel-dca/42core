/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:49:19 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/05 22:12:21 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi(char *str)
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

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}

int	ft_get_index(int *str1, int *str2)
{
	size_t	i;

	i = 0;
	while ((*str1) != (str2)[i])
		i++;
	return (i);
}

int	ft_memcmp(void *str1, void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned int *)str1)[i] != ((unsigned int *)str2)[i])
			return (((int *)str1)[i] - ((int *)str2)[i]);
		i++;
	}
	return (0);
}
