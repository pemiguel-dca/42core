/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/03 16:14:17 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int args, char *argv[])
{
	t_stack	*a;
	int		i;
	int		*copy;

	i = 0;
	a = create_arr(argv, (args - 1));
	copy = copy_a(a);
	proper_sort(copy, a->size);
	printf("Stack A: \n");
	while (i < (args - 1))
	{
		printf("Número %d :%d\n", i + 1, a->array[i]);
		i++;
	}
	printf("Depois do RA: \n");
	rotate_one_stack(RA,a);
	i = 0;
	while (i < (args - 1))
	{
		printf("Número %d :%d\n", i + 1, a->array[i]);
		i++;
	}
	printf("Depois do SA: \n");
	swap_one_stacks(SA,a);
	i = 0;
	while (i < (args - 1))
	{
		printf("Número %d :%d\n", i + 1, a->array[i]);
		i++;
	}
	printf("Max: %d \n", max(a));
	printf("Min: %d \n", min(a));
	free(a);
}
