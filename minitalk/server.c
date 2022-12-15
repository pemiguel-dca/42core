/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:19:20 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/14 19:07:05 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SIGNAL FUNCTION
void (*signal(int sig, void (*func)(int)))(int);
*/

#include "minitalk.h"

static void	receive_data(int signal)
{
	char	curr_bit;
	int		len;
	int		;


}

int main()
{
	int pid;
	struct	sigaction sa;
	pid = getpid(); //getpid() returns the process ID (PID) of the calling process
	ft_putnbr_fd(pid, 1);// escreve o PID na consola
	write(1, "\n", 1);
	sa.sa_handler = &receive_data;
	sigaction(SIGUSR2, &sa, NULL); // funciona exatamente da mesma maneira que o signal, só que é mais portavel
	
}
