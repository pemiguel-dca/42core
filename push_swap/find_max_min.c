/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:39 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/09 00:58:53 by pemiguel         ###   ########.fr       */
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

int	mid_sorted_for_b(int *array, int size)
{
	proper_sort_b(array, size);
	return (array[size / 2]);
}

int	find_pos(int pos, t_stack *stack)//comecando do 0
{
	int	i;

	i = stack->pos_top;
	while (stack->array[i] != pos) // pode vir a ser menos stack-top porque o top aumenta a medida que tiramos um numero, mas vemos depois
		i++;
	return (i - stack->pos_top);
}
