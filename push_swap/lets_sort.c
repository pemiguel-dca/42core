/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 18:11:31 by pemiguel         ###   ########.fr       */
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

void	first_step(t_stack *a, t_stack *b)
{
	while (b->size < 3)
	{
		if (a->array[a->pos_top] == 0 || a->array[a->pos_top] == 1)
			push_b(PB, a, b);
		else
			rotate_one_stack(RA, a, 1);
	}
	when_size_3(a);
}

void	second_step(t_stack *a, t_stack *b)
{
	if (b->array[b->pos_top] < b->array[b->pos_top + 1])
		swap_one_stack(SB, b, 1);
	push_a(PA, a, b);
	push_a(PA, a, b);
}

void	lets_sort(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		when_size_3(a);
	else
	{
		first_step(a, b);
		second_step(a, b);
	}
}
