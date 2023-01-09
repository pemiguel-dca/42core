/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/06 17:15:07 by pemiguel         ###   ########.fr       */
=======
/*   Updated: 2023/01/05 22:06:44 by pemiguel         ###   ########.fr       */
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
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
	unsigned int	i;

	mid = 0;
	i = 0;
	while (compare_stack(array, a))
	{
		i = 0;
		mid = mid_sorted(array + a->pos_top, (a->size - b->size));
		while (a->array[a->pos_top] < mid && (a->size - b->size > 2))
			push_b(PB, a, b);
<<<<<<< HEAD
=======
		if (a->array[a->pos_top + 1] <= mid)
			swap_one_stack(SA, a, 1);
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
		while ((a->pos_top + i) < a->size)
			i++;
		if (compare_stack(array, a))
		{
			if (a->array[a->pos_top + i] < mid)
				rr_one_stack(RRA, a, 1);
			else if (a->array[a->pos_top] >= mid)
				rotate_one_stack(RA, a, 1);
		}
	}
}

void	second_step(t_stack *a, t_stack *b)
{
	int					m;
	unsigned int		b_numb;

	b_numb = b->size;
	m = max(b);
	while (b->size != 0)
	{
		if (b->size == 1)
			push_a(PA, a, b);
		while (b->array[b->pos_top] == m && b->size != 0)
		{
			push_a(PA, a, b);
			m = max(b);
			b_numb--;
		}
		if (b_numb > 2 && b->array[b->pos_top] != m)
		{
			if (find_pos_beg(m, b) > find_pos_end(m, b))
				rr_one_stack(RRB, b, 1);
			else
				rotate_one_stack(RB, b, 1);
		}
	}
}

void	lets_sort(int *array, t_stack *a, t_stack *b)
{
	if (a->size == 3)
		when_size_3(a);
<<<<<<< HEAD
	if (a->size != 3 && a->size < 6)
	{
		first_step(array, a, b);
		second_step(a, b);
	}
=======
	if (a->size < 250)
	{
		first_step(array, a, b);
		second_step(array, a, b);
	}	
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
}
