/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/04 19:10:22 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_b(t_stack *a)
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
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		*copy;

	i = 0;
	a = create_arr(argv, (args - 1));
	b = init_b(a);
	copy = copy_a(a);
	proper_sort(copy, a->size);
	while (i < a->pos_top)
	{
		printf("Número %d :%d\n", i + 1, b->array[i]);
		i++;
	}
	i = 0;
	printf("Stack A: \n");
	while (i < (args - 1))
	{
		printf("Número %d :%d\n", i + 1, a->array[i]);
		i++;
	}
	free(a);
}
