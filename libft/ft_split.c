/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:19:23 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/08 17:06:18 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char charset, char c)
{
	if (charset == c)
		return (1);
	return (0);
}

static int	ft_size_wout_sep(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_checkset(charset, str[i]))
		i++;
	return (i);
}

static int	tam_splited(char *str, char charset)
{
	int	i;
	int	tam;

	i = 0;
	tam = 0;
	while (str[i])
	{
		while (str[i] && ft_checkset(charset, str[i]))
			i++;
		if (str[i])
			tam++;
		while (str[i] && !ft_checkset(charset, str[i]))
			i++;
	}
	return (tam);
}

static char	*phrase_wout_sep(char *str, char charset)
{
	char	*string;
	int		i;
	int		length;

	i = 0;
	length = ft_size_wout_sep(str, charset);
	string = (char *) malloc(length * sizeof(char) + 1);
	if (!string)
		return (NULL);
	while (i < length)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		length_splited;
	int		j;

	j = 0;
	length_splited = tam_splited((char *)s, c);
	splited = (char **) malloc((length_splited + 1) * sizeof(char *));
	if (!splited || !s)
		return (NULL);
	while (*s)
	{
		while (*s && ft_checkset(c, *s))
			s++;
		if (*s)
		{
			splited[j] = phrase_wout_sep((char *)s, c);
			j++;
		}
		while (*s && !ft_checkset(c, *s))
			s++;
	}
	splited[j] = 0;
	return (splited);
}
