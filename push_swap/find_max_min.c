/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:39 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:36:59 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	unsigned int	i;
	int				max;

	i = stack->pos_top;
	max = stack->array[i];
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}

int	min(t_stack *stack)
{
	unsigned int	i;
	int				min;

	min = max(stack);
	i = stack->pos_top;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

int	mid_sorted(int *array, int size)
{
	proper_sort(array, size);
	return (array[size / 2]);
}

int	find_pos_beg(int nb, t_stack *stack)
{
	int	i;
	int	returns;

	i = stack->pos_top;
	returns = 0;
	while (stack->array[i] != nb)
	{
		i++;
		returns++;
	}
	return (returns);
}

int	find_pos_end(int nb, t_stack *stack)
{
	int	i;
	int	returns;

	i = stack->size - 1;
	returns = 0;
	while (stack->array[i] != nb)
	{
		i--;
		returns++;
	}
	return (returns);
}
