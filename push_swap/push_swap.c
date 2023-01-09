/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:02:10 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_arr(char **argv, int size)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	stack_a = malloc(sizeof (*stack_a));
	if (!stack_a)
		return (NULL);
	if (!check_duplicates(argv, size)
		&& !check_int_value(argv) && !check_arr(argv))
	{
		stack_a->array = malloc(size * sizeof(int));
		stack_a->size = size;
		stack_a->pos_top = 0;
		while (argv[i + 1])
		{
			stack_a->array[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	else
	{
		ft_putstr("Error!");
		exit(0);
	}
	return (stack_a);
}

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
	int				*copy;

	a = create_arr(argv, (args - 1));
	b = init(a);
	copy = copy_stack(a);
	proper_sort(copy, a->size);
	duplicate_positive = duplicate_list(a);
	if (a->size > 5)
		sort_with_radix(duplicate_positive, b);
	else
		lets_sort(copy, a, b);
	free(copy);
	free(a->array);
	free(a);
	free(b->array);
	free(b);
	free(duplicate_positive->array);
	free(duplicate_positive);
}
