/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:28:59 by pemiguel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/09 13:06:46 by pemiguel         ###   ########.fr       */
=======
/*   Updated: 2023/01/05 22:10:39 by pemiguel         ###   ########.fr       */
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*For 250 numbers or plus we'll go for the radix sort
<<<<<<< HEAD
The radix sort only works with positive numbers so the idea is
=======
The radix sort only works with positive numbers so the idea is 
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
to create a duplicate list that tranform every number to positive.
EXAMPLE : A-> 2 24 -2 the duplicate will be Dup -> 1 2 0
*/

<<<<<<< HEAD
int	get_max_bits(int max_number)
{
	int	max_bits;

	max_bits = 0;
	while ((max_number >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

=======
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
t_stack	*duplicate_list(t_stack *a)
{
	t_stack			*duplicate_positive;
	int				*organized;
	unsigned int	i;

	duplicate_positive = init(a);
	organized = copy_stack(a);
	proper_sort(organized, a->size);
	i = 0;
	while (i != a->size)
	{
		duplicate_positive->array[i] = ft_get_index(&a->array[i], organized);
		i++;
	}
	duplicate_positive->size = a->size;
	duplicate_positive->pos_top = 0;
<<<<<<< HEAD
	free(organized);
=======
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
	return (duplicate_positive);
}

void	sort_with_radix(t_stack *dup, t_stack *b)
{
	unsigned int	max_number;
	unsigned int	max_bits;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
<<<<<<< HEAD
	max_number = dup->size - 1;
	max_bits = get_max_bits(max_number);
=======
	max_bits = 0;
	max_number = dup->size - 1;
	while ((max_number >> max_bits) != 0)
		max_bits++;
>>>>>>> 65a48047b4085210e45117414187cde10a0705aa
	while (++i < max_bits)
	{
		j = -1;
		while (++j < dup->size)
		{
			if (((dup->array[dup->pos_top] >> i) & 1) == 0)
				push_b(PB, dup, b);
			else
				rotate_one_stack(RA, dup, 1);
		}
		while (b->size != 0)
			push_a(PA, dup, b);
		if (b->size == 0)
			b->pos_top = 0;
	}
}
