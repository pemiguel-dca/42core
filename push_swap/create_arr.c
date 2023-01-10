/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:43:59 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 21:49:22 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_only_minus(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], ONLY_MINUS))
			return (1);
	}
	return (0);
}

int	check_arr(char **argv)
{
	int	i;
	int	j;
	int	c_minus;

	i = 1;
	while (argv[i])
	{
		j = 0;
		c_minus = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || ft_isdigit(argv[i][j]))
			{
				if (argv[i][j] == '-')
					c_minus++;
				j++;
			}
			else
				return (1);
			if (c_minus > 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_int_value(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((int)ft_strlen(argv[i]) != len_dec(ft_atoi(argv[i])))
			return (1);
		i++;
	}
	return (0);
}

int	*create_keep_intg(char **argv, int size)
{
	int	i;
	int	*keep_intg;

	keep_intg = malloc(size * sizeof(int));
	if (!keep_intg)
		return (0);
	i = 0;
	while (argv[i + 1])
	{
		keep_intg[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (keep_intg);
}

int	check_duplicates(char **argv, int size)
{
	int	i;
	int	j;
	int	*keep_intg;

	keep_intg = create_keep_intg(argv, size);
	j = 0;
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (keep_intg[i] == keep_intg[j])
			{
				free(keep_intg);
				return (1);
			}
		}
	}
	free(keep_intg);
	return (0);
}
