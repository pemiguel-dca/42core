/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:02:28 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 22:17:40 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_memcmp(void *str1, void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned int *)str1)[i] != ((unsigned int *)str2)[i])
			return (((int *)str1)[i] - ((int *)str2)[i]);
		i++;
	}
	return (0);
}

int	compare_stack(int *array, t_stack *stack)
{
	int	n;

	n = stack->size;
	if (ft_memcmp(stack->array, array, n))
		return (1);
	return (0);
}

void	first_step(t_stack *a, t_stack *b)
{
	while (b->size != 2)
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

void	lets_sort(int *copy_arr, t_stack *a, t_stack *b)
{
	if (a->size == 3)
		when_size_3(a);
	else if (compare_stack(copy_arr, a))
	{
		first_step(a, b);
		second_step(a, b);
	}
}
