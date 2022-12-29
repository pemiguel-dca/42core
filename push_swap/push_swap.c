/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/22 20:47:31 by pemiguel         ###   ########.fr       */
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

int	main(int args, char *argv[])//while (ft_strcmp((char *)copy, (char *)a->array))
{
	t_stack			*a;
	t_stack			*b;
	int				*copy;

	a = create_arr(argv, (args - 1));
	b = init_b(a);
	copy = copy_stack(a);
	proper_sort(copy, a->size);
	if (a->size > 0)
		lets_sort(copy, a, b);
	
	unsigned int	i;
	printf("Stack B: \n");
	i = b->pos_top;
	while (i < b->size)
	{
		printf("Número %d :%d\n", i + 1, b->array[i]);
		i++;
	}
	printf("Stack A: \n");
	i = a->pos_top;
	while (i < a->size)
	{
		printf("Número %d :%d\n", i + 1, a->array[i]);
		i++;
	}
	
	free(a);
}
