/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/07 23:28:19 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		final_comparison(int *array, t_stack *a)
{
	int	n;
	
	n = a->size;
	if (ft_memcmp(a->array, array, n))
		return (1);
	return (0);
}

int		compare_stack(int *array, t_stack *stack)
{
	int	n;

	n = stack->size - stack->pos_top - 1;
	if (ft_memcmp(stack->array + stack->pos_top, array + stack->pos_top, n))
		return (1);
	return (0);
}

void	first_step(int *array, t_stack *a, t_stack *b)
{
	int				mid;
	unsigned int	i;

	mid = mid_sorted(array + a->pos_top, a->size);
	i = 0;
	while (compare_stack(array, a))
	{
		if (a->array[a->pos_top] < mid) //mudar para if no fim
		{	
			push_b(PB, a, b);
			mid = mid_sorted(array + a->pos_top, (a->size - b->size));
		}
		if (a->array[a->pos_top + 1] == min(a) && (a->size - b->size < 3))
				swap_one_stack(SA, a, 1);
		while (a->pos_top + i < a->size)
			i++;
		if ((a->size - b->size > 2))
		{
			if (a->array[a->pos_top + i] < mid)
				rr_one_stack(RRA, a, 1);
			else if (a->array[a->pos_top] >= mid)
				rotate_one_stack(RA, a, 1);
		}
	}
}

void	second_step(int *array, t_stack *a, t_stack *b)
{
	int				numbers_b;
	int				m;

	numbers_b = b->size;
	m = max(b);
	while (final_comparison(array, a))
	{
		while (b->array[b->pos_top] == m && numbers_b > 0)
		{
			push_a(PA, a, b);
			m = max(b);
			numbers_b--;
		}
		if (numbers_b > 1)
		{
			if (b->array[b->pos_top + 1] == m)
				swap_one_stack(SB, b, 1);
		}
		if (a->array[a->pos_top + 1] < a->array[a->pos_top] && numbers_b >= 1)
			swap_one_stack(SA, a, 1);
		if (numbers_b > 2 && b->array[b->pos_top] != m)
		{
			if (find_max_pos(m, b) >= (int)numbers_b / 2)
				rr_one_stack(RRB, b, 1);
			else if (find_max_pos(m, b) < (int)numbers_b / 2)
				rotate_one_stack(RB, b, 1);
		}
	}
}

void	lets_sort(int *array, t_stack *a, t_stack *b)
{
	first_step(array, a, b);
	second_step(array, a, b);
}
