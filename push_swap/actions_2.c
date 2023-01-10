/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:09:08 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 22:08:33 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_one_stack(char *name_ac, t_stack *stack, int how_much)
{
	int		i;
	int		first_number;

	first_number = stack->array[stack->size - 1];
	i = stack->size - 1;
	while (i > stack->pos_top)
	{
		swap(&stack->array[i], &stack->array[(i - 1)]);
		i--;
	}
	stack->array[i] = first_number;
	if (how_much == 1)
		ft_putstr_fd(name_ac, STDOUT_FILENO);
}

void	ss(char *name_ac, t_stack *a, t_stack *b)
{
	swap_one_stack(SA, a, 2);
	swap_one_stack(SB, b, 2);
	ft_putstr_fd(name_ac, STDOUT_FILENO);
}

void	rr(char *name_ac, t_stack *a, t_stack *b)
{
	rotate_one_stack(RA, a, 2);
	rotate_one_stack(RB, b, 2);
	ft_putstr_fd(name_ac, STDOUT_FILENO);
}

void	rrr(char *name_ac, t_stack *a, t_stack *b)
{
	rr_one_stack(RRA, a, 2);
	rr_one_stack(RRB, b, 2);
	ft_putstr_fd(name_ac, STDOUT_FILENO);
}
