/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:39:33 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/05 17:34:00 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*move;

	if (!lst)
		return (0);
	while (*lst != NULL)
	{
		move = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = move;
	}
	return (0);
}
