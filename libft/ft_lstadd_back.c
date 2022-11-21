/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:31:57 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/08 18:46:33 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*sp;

	if (lst)
	{
		if (*lst)
		{
			sp = ft_lstlast(*lst);
			sp->next = new;
		}
		else
			*lst = new;
	}	
}
