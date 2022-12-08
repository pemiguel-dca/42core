/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/08 20:29:03 by pemiguel         ###   ########.fr       */
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

	mid = 0;
	i = 0;
	while (compare_stack(array, a))
	{
		mid = mid_sorted(array + a->pos_top, (a->size - b->size));
		while (a->array[a->pos_top] < mid && (a->size - b->size > 2))
			push_b(PB, a, b);
		if (a->array[a->pos_top + 1] < mid)
				swap_one_stack(SA, a, 1);
		while (a->pos_top + i < a->size)
			i++;
		if (compare_stack(array, a))
		{
			if (a->array[a->pos_top + i] <= mid)
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
	unsigned int	i;
	int				*sorted_b;

	sorted_b = copy_stack(b);
	proper_sort_b(sorted_b, b->size);
	numbers_b = b->size;
	m = mid_sorted(sorted_b + b->pos_top, (numbers_b - b->pos_top));
	printf("Mid B:%d", m);
	while (final_comparison(array, a) && numbers_b > 0)
	{
		i = 0;
		while ((b->array[b->pos_top] > m && numbers_b > 0))
		{
			push_a(PA, a, b);
			if (a->array[a->pos_top + 1] < a->array[a->pos_top] || numbers_b == 1)
				swap_one_stack(SA, a, 1);
			numbers_b--;
			m = mid_sorted(sorted_b + b->pos_top, (numbers_b - b->pos_top));
		}
		if ((b->array[b->pos_top + 1] > m  && b->array[b->size - 1] < m ) && numbers_b > 2)
			swap_one_stack(SB, b, 1);
		while (b->pos_top + i < (unsigned int)numbers_b)
			i++;
		if (numbers_b > 2)
		{
			if (b->array[b->pos_top + i] >= m)
				rr_one_stack(RRB, b, 1);
			else if (b->array[b->pos_top] <= m)
				rotate_one_stack(RB, b, 1);
		}
	}
}

void	lets_sort(int *array, t_stack *a, t_stack *b)
{
	if (a->size == 3)
		when_size_3(a);
	first_step(array, a, b);
	second_step(array, a, b);
}
