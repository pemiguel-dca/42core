/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:11:19 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/02 15:34:56 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_a(t_stack *a)
{
	int				*c;
	int				array_c[1024];
	unsigned int	i;

	i = 0;
	c = malloc(a->size * sizeof(int));
	while (i != a->size)
	{
		array_c[i] = a->array[i];
		i++;
	}
	c = array_c;
	return (c);
}

void	proper_sort(int *tab, int size)
{
	int	x;
	int	y;
	int	swap;

	x = 1;
	while (x < size)
	{
		swap = tab[x];
		y = x - 1;
		while (y >= 0 && tab[y] > swap)
		{
			tab[y + 1] = tab[y];
			y = y - 1;
		}
		tab[y + 1] = swap;
		x++;
	}
}
