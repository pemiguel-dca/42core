/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:03:12 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/09 22:56:44 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	swap_one_stack(char *name_ac, t_stack *stack, int how_much)
{
	swap(&stack->array[stack->pos_top], &stack->array[stack->pos_top + 1]);
	if (how_much == 1)
		ft_putstr(name_ac);
}

void	rotate_one_stack(char *name_ac, t_stack *stack, int how_much)
{
	unsigned int	i;
	int				first_number;

	first_number = stack->array[stack->pos_top];
	i = stack->pos_top;
	while (i < stack->size)
	{
		swap(&stack->array[i], &stack->array[(i + 1)]);
		i++;
	}
	stack->array[i - 1] = first_number;
	if (how_much == 1)
		ft_putstr(name_ac);
}

void	push_b(char *name_ac, t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = b->pos_top;
	b->size++;
	if (a->pos_top != 0)
	{
		while (i < b->size)
		{
			swap(&b->array[i], &b->array[(a->pos_top)]);
			i++;
		}
	}
	b->array[b->pos_top] = a->array[a->pos_top];
	a->array[a->pos_top] = 0;
	a->pos_top++;
	ft_putstr(name_ac);
}

void	push_a(char *name_ac, t_stack *a, t_stack *b)
{
	int	previous_top;

	previous_top = a->array[a->pos_top + 1];
	printf("Previous Top:%d", previous_top);
	a->array[a->pos_top] = b->array[b->pos_top];
	if (previous_top < a->array[a->pos_top])
		swap_one_stack(SA, a, 1);
	b->array[b->pos_top] = 0;
	b->pos_top++;
	ft_putstr(name_ac);
}
