/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:36 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/02 15:21:48 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
	SIGUSR1 sends 0
	SIGUSR2 sends 1
*/

static void	receive_data(int signal, siginfo_t *info, void *nedeed)
{
	static int		curr_bit = 0;
	int				client_pid;
	static char		ascii = 0;

	(void)nedeed;
	client_pid = info->si_pid;
	if (signal == SIGUSR2)
		ascii += 1 << curr_bit;
	if (curr_bit == 7)
	{
		write(1, &ascii, 1);
		ascii = 0;
		curr_bit = 0;
		kill(client_pid, SIGUSR2);
	}
	else
		curr_bit++;
	usleep(0);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = receive_data;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
}
