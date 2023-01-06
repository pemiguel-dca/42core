/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/05 22:31:28 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof (*b));
	b->size = 0;
	b->pos_top = 0;
	b->array = malloc(a->size * sizeof(int));
	return (b);
}

int	main(int args, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*duplicate_positive;

	a = create_arr(argv, (args - 1));
	b = init(a);
	duplicate_positive = duplicate_list(a);
	sort_with_radix(duplicate_positive, b);
	free(a);
	free(duplicate_positive);

	//strlen está na exception.c porque nao havia mais espaço nos helpers
}
