/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:40:23 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/08 19:00:53 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = (char *) malloc(ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1 * sizeof(char));
	if (!res)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (j < ft_strlen((char *)s2))
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
