/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:00:20 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/07 14:12:29 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*move;
	t_list		*position_new;
	t_list		*position_old;

	move = ft_lstnew((*f)(lst->content));
	if (!lst || !move)
		return (NULL);
	position_new = move;
	position_old = lst->next;
	while (position_old)
	{
		position_new->next = ft_lstnew((*f)(position_old->content));
		if (!(position_new->next))
		{
			ft_lstclear(&move, del);
			return (NULL);
		}
		position_new = position_new->next;
		position_old = position_old->next;
	}
	return (move);
}
