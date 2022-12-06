/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/06 19:58:16 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		compare_stack(int *array, t_stack *stack)
{
	int	n;

	n = stack->size - stack->pos_top - 1;
	if (ft_memcmp(&stack->array[stack->pos_top], &array[stack->pos_top], n))
		return (1);
	return (0);
}

void	lets_sort(int *array, t_stack *a, t_stack *b)
{
	int	mid;
	unsigned int	i;

	mid = 0;
	while (compare_stack(array, a)) //enquanto eles nao forem iguais, enquanto A nao tiver organizado
	{
		i = 0;
		mid = mid_sorted(array + a->pos_top, (a->size - b->size));
		while (a->array[a->pos_top] < mid) //mudar para if no fim
			push_b(PB, a, b);
		while (a->pos_top + i < a->size)
			i++;
		if ((a->size - b->size > 2))
		{
			if (a->array[a->size - 1] == max(a) && a->array[a->pos_top + 1] == min(a))
				swap_one_stack(SA, a, 1);
			if (a->array[a->pos_top + (i - 1)] < mid)
				rr_one_stack(RRA, a, 1);
			else if (a->array[a->pos_top] >= mid)
				rotate_one_stack(RA, a, 1);
		}
	}
	while (b->size != 0)
	{

	}

}
