/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:39 by pemiguel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/09 13:03:55 by pemiguel         ###   ########.fr       */
=======
/*   Updated: 2023/01/05 22:01:56 by pemiguel         ###   ########.fr       */
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
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

	i = stack->size;
	returns = 0;
	while (stack->array[i] != nb)
	{
		i--;
		returns++;
	}
	return (returns);
}
