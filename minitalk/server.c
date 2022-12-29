/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:19:20 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/22 15:36:33 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
	SIGUSR1 sends 0
	SIGUSR2 sends 1
*/

static void	check_bit_and_print(char *ascii, int *bit)
{
	write(1, ascii, 1);
	*ascii = 0;
	*bit = 0;
}
static void	receive_data(int signal, siginfo_t *info, void *nedeed)
{
	static int		curr_bit;
	static int		actual_pid;
	static int		client_pid;
	static char		ascii;

	(void)nedeed;
	if (!client_pid)
		client_pid = info->si_pid;
	actual_pid = info->si_pid;
	if (client_pid != actual_pid)// se mudarmos de client PID resetamos as variaveis
	{
		client_pid = actual_pid;
		curr_bit = 0;
		ascii = 0;
	}
	if (signal == SIGUSR2)
		ascii += ft_recursive_power(2, curr_bit);
	curr_bit++;
	if (curr_bit == 8)
		check_bit_and_print(&ascii, &curr_bit);
	usleep(100);
	//kill(client_pid, SIGUSR2); suposto mandar sinal ao cliente mas está a mandar para o servidor(???)
}

int main()
{
	int 	pid;
	struct	sigaction sa;

	sa.sa_sigaction = receive_data;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid(); //getpid() returns the process ID (PID) of the calling process
	write(1, "PID : ", 6);
	ft_putnbr_fd(pid, 1);// escreve o PID na consola
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
}
