/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:03:12 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/03 18:19:45 by pemiguel         ###   ########.fr       */
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

void	swap_one_stacks(char *name_ac, t_stack *stack)
{
	swap(&stack->array[0], &stack->array[1]);
	ft_putstr(name_ac);
	write(1, "\n", 1);
}

void	rotate_one_stack(char *name_ac, t_stack *stack)
{
	unsigned int	i;
	int	first_number;

	first_number = stack->array[0];
	i = 0;
	while (i < stack->size)
	{
			swap(&stack->array[i],&stack->array[(i + 1)]);
		i++;
	}
	stack->array[stack->size - 1] = first_number;
	ft_putstr(name_ac);
	write(1, "\n", 1);
}

//Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	push(char *name_ac, t_stack *a, t_stack *b)
{
	unsigned int	i;
	if (!b->size)
		b = malloc(a->size * sizeof(t_stack));
	a->size--;
	b->size++;
	if (b->size > 1)
		b->array = ft_calloc(a->size, sizeof(int));
	if (ft_strcmp(name_ac, PB))
	{
		b->array[0] = a->array[0];
		while (i < b->size)
		{


			i++;
		}
	}
	else if (ft_strcmp(name_ac, PA))//pa
}
