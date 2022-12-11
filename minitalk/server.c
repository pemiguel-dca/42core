/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:19:20 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/11 16:49:21 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SIGNAL FUNCTION
void (*signal(int sig, void (*func)(int)))(int);
*/

#include "minitalk.h"

int main()
{
	int pid;

	pid = getpid(); //getpid() returns the process ID (PID) of the calling process.  (This is often used by routines that generate unique temporary filenames.)
	ft_putnbr_fd(pid, 1);// escreve o PID na consola
	write(1, "\n", 1);
	signal(SIGUSR1)
}
