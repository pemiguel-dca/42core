/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/05 19:21:00 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_sort(int *array, t_stack *a, t_stack *b)
{
	int	mid;
	int	i;

	i = 0;
	proper_sort(array, a->size);

	mid = mid_sorted(&array[a->pos_top], a->size);
	while (a->array[a->pos_top] < mid)
		push_b(PB, a, b);
	while (a->array[a->pos_top + i])
		i++;
	if (a->array[a->pos_top + (i - 1)] < mid)
		rr_one_stack(RRA, a, 1);
	if (a->array[a->pos_top >= mid])
		rotate_one_stack(RA, a, 1);
	if (b->size == a->size / 2)
	{
		mid = mid_sorted(&array[a->pos_top], (a->size - b->size));
		while (a->array[a->pos_top] < mid)
			push_b(PB, a, b);
		while (a->array[a->pos_top + i])
			i++;
		if (a->array[a->pos_top + (i - 1)] < mid)
			rr_one_stack(RRA, a, 1);
		if (a->array[a->pos_top >= mid])
			rotate_one_stack(RA, a, 1);
	}
	if (ft_strcmp((char *)&a->array + a->pos_top, (char *)array + a->pos_top) == 0)
	{
		printf("Entrei\n");
	}
}
