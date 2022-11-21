/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:46:53 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/21 16:47:33 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*file descritors standard -> 0, 1, 2*/
/*We use the file descriptor number '3' to open .txt files */

#include "get_next_line.h"

char	*ac_lines(int fd, char *str)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_line_dep_buffer(char *fline)
{
	char	*act_line;
	size_t	i;

	i = 0;
	if (!fline[i])
		return (NULL);
	while (fline[i] && fline[i] != '\n')
		i++;
	act_line = (char *)malloc(i + 2 * sizeof(char));
	if (!act_line)
		return (NULL);
	i = 0;
	while (fline[i] && fline[i] != '\n')
	{
		act_line[i] = fline[i];
		i++;
	}
	if (fline[i] == '\n')
	{
		act_line[i] = fline[i];
		i++;
	}
	act_line[i] = '\0';
	return (act_line);
}

char	*next_line(char *fline)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (fline[i] && fline[i] != '\n')
		i++;
	if (!fline[i])
	{
		free(fline);
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(fline) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (fline[i])
		next_line[j++] = fline[i++];
	next_line[j] = '\0';
	free(fline);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*run_lines[4096];
	char		*act_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	run_lines[fd] = ac_lines(fd, run_lines[fd]);
	if (!run_lines[fd])
		return (NULL);
	act_line = get_line_dep_buffer(run_lines[fd]);
	run_lines[fd] = next_line(run_lines[fd]);
	return (act_line);
}
/*
int	main()
{
	int	fd;
	size_t	lines;
	fd = open("test.txt", O_RDONLY);
	lines = 1;
	while (lines-- != 0)
		printf("%s", get_next_line(fd));	
}*/
