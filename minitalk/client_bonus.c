/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:09 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/02 15:21:26 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(100);
	}
}

int	confirm_params(int n_params, char **argv)
{
	int	i;

	i = 0;
	if (n_params != 2)
		return (1);
	while (argv[1][i])
	{
		if (!ft_strchr(DEC_BASE, argv[1][i++]))
			return (1);
	}
	return (0);
}

void	message_recieved(int sig)
{
	if (sig == SIGUSR2)
		printf("Signal sent successfully!\n");
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (!confirm_params(argc - 1, argv))
	{
		signal(SIGUSR1, &message_recieved);
		signal(SIGUSR2, &message_recieved);
		while (*str)
			send_binary_char(*str++, pid);
	}
}
