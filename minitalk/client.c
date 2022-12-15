/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:37:09 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/14 17:05:40 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
kill function prototype, send the pid and the signal, returns 0 if non error found
int kill(pid_t pid, int sig);*/

/*Since this is a PROJECT we are needing the main.
The PID sent by us can't be nothing but numbers, so
we have to use a function to check if the PID passed is valid
*/

#include "minitalk.h"

void	send_length_str(int length, int pid)
{
	int	i;

	i = 0;
	while (i <= 32)
	{
		if (length & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		length = length >> 1;
		i++;
		usleep(SLEEP);
	}
}

void	send_binary_char(char c, int pid)
{
	int	i; // vai correr ate chegar a 8 bits, porque 1 byte = 8 bits, 1 byte pois sizeof(char) = 1 byte

	i = 0;
	while (i <= 8)
	{
		if (c & 1) //compara(bitwise) se c == 1
			kill(pid, SIGUSR2); //sending 1
		else
			kill(pid, SIGUSR1); //sending 0
		c = c >> 1; //avanca para a direita da representacao binaria EXEMPLO : 1001 >> 1 = 0100
		i++;
		usleep(SLEEP);
	}
}

int	confirm_params(int n_params, char **argv)
{
	int i;

	i = 0;
	if (n_params != 3)
		return (1);
	while (argv[1][i])
	{
		if (!ft_strchr(DEC_BASE, argv[1][i++]))// se existir algo para alem dos numeros daquela base, ERRO, pois o pid sao so numeros
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int 	pid;
	size_t	len;
	char	*str; // string to send

	str = argv[2];
	len = ft_strlen(str);
	if (!confirm_params(argc - 1, argv))
	{
		send_length_str(len, pid);
		while (*str)
			send_binary_char(*str++, pid);
		send_binary_char(*str++, pid); //para o nulo (I GUESS)
	}
	return (0);
}