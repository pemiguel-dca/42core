/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:31:07 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/08 12:40:31 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	when_size_3(t_stack *a)
{
	if (a->array[0] < a->array[1] && a->array[0] < a->array[2]
		&& a->array[1] == max(a))
	{
		swap_one_stack(SA, a, 1);
		rotate_one_stack(RA, a, 1);
	}
	else if (a->array[2] == max(a) && a->array[1] == min(a))
		swap_one_stack(SA, a, 1);
	else if (a->array[0] == max(a) && a->array[2] == min(a))
	{
		swap_one_stack(SA, a, 1);
		rr_one_stack(RRA, a, 1);
	}
	else if (a->array[0] == max(a) && a->array[1] == min(a))
		rotate_one_stack(RA, a, 1);
	else if (a->array[1] == max(a) && a->array[2] == min(a))
		rr_one_stack(RRA, a, 1);
}
