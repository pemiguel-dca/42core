/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:29:48 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/04 18:02:21 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*sp;
	int		i;

	sp = lst;
	i = 0;
	while (sp)
	{
		sp = sp->next;
		i++;
	}
	return (i);
}
