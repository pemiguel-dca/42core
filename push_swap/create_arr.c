/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:43:59 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/05 22:30:34 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!ft_strcmp(argv [i], ONLY_MINUS))
			return (1);
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

int	len_dec(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
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

int	check_duplicates(char **argv, int size)
{
	int	i;
	int	j;
	int	*keep_intg;

	keep_intg = malloc(size * sizeof(int));
	i = 0;
	while (argv[i + 1])
	{
		keep_intg[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (keep_intg[i] == keep_intg[i + j++])
				return (1);
		}
		i++;
	}
	free(keep_intg);
	return (0);
}

t_stack	*create_arr(char **argv, int size)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	stack_a = malloc(sizeof (*stack_a));
	if (!stack_a)
		return (NULL);
	if (!check_duplicates(argv, size)
		&& !check_int_value(argv) && !check_arr(argv))
	{
		stack_a->array = malloc(size * sizeof(int));
		stack_a->size = size;
		stack_a->pos_top = 0;
		while (argv[i + 1])
		{
			stack_a->array[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	else
	{
		ft_putstr("Error!");
		exit(0);
	}
	return (stack_a);
}
