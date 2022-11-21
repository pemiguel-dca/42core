/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:27:53 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/10 16:09:20 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str) + 1;
	while (--i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&(str[i]));
	}
	return (NULL);
}
