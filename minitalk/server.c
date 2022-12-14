/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:19:20 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/14 18:31:57 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SIGNAL FUNCTION
void (*signal(int sig, void (*func)(int)))(int);
*/

#include "minitalk.h"

static void	receive_data(int signal)
{
	int		length;
	int 	i;
	char	curr_bit;


}

int main()
{
	int pid;
	struct	sigaction sa;
	sa.
	pid = getpid(); //getpid() returns the process ID (PID) of the calling process
	ft_putnbr_fd(pid, 1);// escreve o PID na consola
	write(1, "\n", 1);
	signal(SIGUSR1, receive_data);
}
