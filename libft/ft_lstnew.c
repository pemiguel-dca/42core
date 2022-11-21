/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:33:54 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/08 17:57:13 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*spointer;

	spointer = (t_list *)malloc(sizeof(t_list));
	if (!spointer)
		return (NULL);
	spointer->content = content;
	spointer->next = NULL;
	return (spointer);
}
