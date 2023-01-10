/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:31:07 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 21:51:53 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)src)[i] = c;
		i++;
	}
	return (src);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total;
	void	*ptr;

	total = nitems * size;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	when_size_3(t_stack *a)
{
	if (a->array[a->pos_top] < a->array[a->pos_top + 1]
		&& a->array[a->pos_top] < a->array[a->pos_top + 2]
		&& a->array[a->pos_top + 1] == max(a))
	{
		swap_one_stack(SA, a, 1);
		rotate_one_stack(RA, a, 1);
	}
	else if (a->array[a->pos_top + 2] == max(a)
		&& a->array[a->pos_top + 1] == min(a))
		swap_one_stack(SA, a, 1);
	else if (a->array[a->pos_top] == max(a)
		&& a->array[a->pos_top + 2] == min(a))
	{
		swap_one_stack(SA, a, 1);
		rr_one_stack(RRA, a, 1);
	}
	else if (a->array[a->pos_top] == max(a)
		&& a->array[a->pos_top + 1] == min(a))
		rotate_one_stack(RA, a, 1);
	else if (a->array[a->pos_top + 1] == max(a)
		&& a->array[a->pos_top + 2] == min(a))
		rr_one_stack(RRA, a, 1);
}
