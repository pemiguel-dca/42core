/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:37:09 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/11 17:56:38 by pemiguel         ###   ########.fr       */
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

int	confirm_params(int n_params, char *argv[])
{
	int i;

	i = 0;
	if (n_params != 3)
		return (1);
	while (argv[1][i])
	{
		if (!ft_strchr(DEC_BASE, argv[1][i++]))
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	//int pid;

	printf("%d", confirm_params(argc, argv));

}
