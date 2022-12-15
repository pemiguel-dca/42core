/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/09 22:58:23 by pemiguel         ###   ########.fr       */
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

int		compare_while_running(int *array, t_stack *stack, int i)
{
	int	n;

	n = stack->size - (stack->pos_top + i) - 1;
	if (ft_memcmp(stack->array + (stack->pos_top + i), array + (stack->pos_top + i), n))
		return (1);
	return (0);
}

void	first_step(int *array, t_stack *a, t_stack *b)
{
	int				mid;
	unsigned int	i;
	int	run;
	//unsigned int j;

	run = 1;
	mid = 0;
	i = 0;
	while (compare_stack(array, a))
	{
		i = 0;
		run = 1;
		mid = mid_sorted(array + a->pos_top, (a->size - b->size));
		while (a->array[a->pos_top] < mid && (a->size - b->size > 2))
			push_b(PB, a, b);
		if (a->array[a->pos_top + 1] <= mid)	
		{
			//while (compare_while_running(array, a, run))
			//	run++;
			if (run < a->pos_top)
				swap_one_stack(SA, a, 1);
		}
		while ((a->pos_top + i) < a->size)
			i++;
		//j = find_pos(mid, a);
		if (compare_stack(array, a))
		{
			//comparar o que esta mais proximo do meio e ver qual vale mais apena fazer
			if (a->array[a->pos_top + i] < mid)
				rr_one_stack(RRA, a, 1);
			else if (a->array[a->pos_top] >= mid)
				rotate_one_stack(RA, a, 1);
		}
	}
}

void	second_step(int *array, t_stack *a, t_stack *b)
{
	int					m;
	int					*sorted_b;
	unsigned int		i;
	unsigned int		b_numb;

	b_numb = b->size;
	sorted_b = copy_stack(b);
	m = 0;
	i = 0;
	array++;
	while (b_numb != 93)
	{
		i = 0;
		m = mid_sorted_for_b(sorted_b + b->pos_top, b_numb);
		if (b_numb == 2 && (b->array[b->pos_top] < b->array[b->pos_top + 1]))
			swap_one_stack(SB, b, 1);
		if (b_numb == 1 || b_numb == 2)
		{
			push_a(PA, a, b);
			b_numb--;
		}
		while (b->array[b->pos_top] > m && b_numb > 93)
		{
			a->pos_top--;
			push_a(PA, a, b);
			b_numb--;
		}
		if (b_numb > 2)
		{
			while ((b->pos_top + i) < b->size)
				i++;
			if (b->array[b->pos_top + i] > m)
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
