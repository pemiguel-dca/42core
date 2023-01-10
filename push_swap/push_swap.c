/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 22:27:23 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(int *copy_arr, t_stack *a, t_stack *b, t_stack *dup)
{
	free(copy_arr);
	free(a->array);
	free(a);
	free(b->array);
	free(b);
	free(dup->array);
	free(dup);
}

t_stack	*create_arr(char **argv, int size)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	if (!check_duplicates(argv, size) && !check_only_minus(argv)
		&& !check_int_value(argv) && !check_arr(argv))
	{
		stack_a = malloc(sizeof (*stack_a));
		if (!stack_a)
			return (NULL);
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
		ft_putstr_fd("Error!\n", STDERR_FILENO);
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
	b->array = calloc(a->size, sizeof(int));
	return (b);
}

int	main(int args, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*duplicate_positive;
	int				*copy_arr;

	if (args == 1)
		exit(0);
	a = create_arr(argv, (args - 1));
	b = init(a);
	duplicate_positive = duplicate_list(a);
	copy_arr = copy_stack(duplicate_positive);
	proper_sort(copy_arr, duplicate_positive->size);
	if (a->size > 5 && compare_stack(copy_arr, duplicate_positive))
		sort_with_radix(duplicate_positive, b);
	else
		lets_sort(copy_arr, duplicate_positive, b);
	free_all(copy_arr, a, b, duplicate_positive);
}
