/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:56:41 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/14 16:28:57 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define DEC_BASE "0123456789"
# define SLEEP 100

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//Utils
size_t	ft_strlen(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *str, int c);

//Client
void	send_binary_char(char c, int pid);
int		confirm_params(int n_params, char **argv);
void	send_length_str(int length, int pid);

//Server

#endif
