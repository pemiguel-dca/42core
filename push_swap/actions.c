/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:03:12 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/04 19:07:06 by pemiguel         ###   ########.fr       */
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
	int	i;

	i = 0;
	b->size++;
	if (a->pos_top != 0)
	{
		while (i < a->pos_top)
		{
			swap(&b->array[i], &b->array[(a->pos_top)]);
			i++;
		}
	}
	b->array[0] = a->array[a->pos_top];
	a->pos_top++;
	if (a->pos_top == (int)a->size)
		a->pos_top = -1;
	ft_putstr(name_ac);
}

void	push_a(char *name_ac, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (b->pos_top != 0)
	{
		while (i < b->pos_top)
		{
			swap(&a->array[i], &a->array[(b->pos_top)]);
			i++;
		}
	}
	a->array[0] = b->array[b->pos_top];
	b->pos_top++;
	if (b->pos_top == (int)b->size)
		b->pos_top = -1;
	a->pos_top--;
	ft_putstr(name_ac);
}
