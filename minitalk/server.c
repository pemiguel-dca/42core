/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:19:20 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/15 16:59:09 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SIGNAL FUNCTION
void (*signal(int sig, void (*func)(int)))(int);
*/

#include "minitalk.h"
/*
	SIGUSR1 sends 0
	SIGUSR2 sends 1
*/

static void	runs_bits(int *bit, int *c, int signal)
{
		if (signal == SIGUSR2)
		{
			bit--;
			*c = ft_recursive_power(2, *bit);
			write(1, &bit, 1);
		}
		else
			bit--;
		if (*bit == 7)
		{
			*c = ft_recursive_power(2, *bit);
			*bit = 0;
		}
}
static void	receive_data(int signal)
{
	static int	curr_bit;
	int 		dec_ascii;

	if (!curr_bit)
		curr_bit = 8;

	runs_bits(&curr_bit, &dec_ascii, signal);
	write(1, &dec_ascii, 1);

}

int main()
{
	int pid;
	struct	sigaction sa;
	pid = getpid(); //getpid() returns the process ID (PID) of the calling process
	write(1, "PID : ", 6);
	ft_putnbr_fd(pid, 1);// escreve o PID na consola
	write(1, "\n", 1);
	sa.sa_handler = &receive_data;
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL); // funciona exatamente da mesma maneira que o signal, só que é mais portavel
		sigaction(SIGUSR1, &sa, NULL);
		pause(); // para ate receber outro sinal
	}
}
