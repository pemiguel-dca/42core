/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 16:19:50 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_stack(int *array, t_stack *stack)
{
	int	n;

	n = stack->size - stack->pos_top - 1;
	if (ft_memcmp(stack->array + stack->pos_top, array + stack->pos_top, n))
		return (1);
	return (0);
}

int	final_comparison(int *array, t_stack *a)
{
	int	n;

	n = a->size;
	if (ft_memcmp(a->array, array, n))
		return (1);
	return (0);
}

void	first_step(int *array, t_stack *a, t_stack *b)
{
	int				mid;

	mid = mid_sorted(array + a->pos_top, (a->size - b->size));
	while (compare_stack(array, a))
	{
		mid = mid_sorted(array + a->pos_top, (a->size - b->size));
		while (a->array[a->pos_top] < mid)
			push_b(PB, a, b);
		if (a->array[a->pos_top] >= mid && (a->size - b->size) > 1)
			rotate_one_stack(RA, a, 1);
	}
}

void	second_step(t_stack *a, t_stack *b)
{
	int					m;

	m = max(b);
	while (b->size != 0)
	{
		if (b->size == 1)
			push_a(PA, a, b);
		while (b->array[b->pos_top] == m && b->size != 0)
		{
			push_a(PA, a, b);
			m = max(b);
		}
		if (b->array[b->pos_top] != m)
			rotate_one_stack(RB, b, 1);
	}
}

void	lets_sort(int *array, t_stack *a, t_stack *b)
{
	if (a->size == 3)
		when_size_3(a);
	if (a->size != 3 && a->size < 6)
	{
		first_step(array, a, b);
		second_step(a, b);
	}
}
