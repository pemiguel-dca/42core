/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:19:59 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:13:06 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	requirements()
{
	ft_putstr_fd("In this program you well be able to experience absolute beauty.\n", 1);
	ft_putstr_fd("For that I will need your help.\n", 1);
	ft_putstr_fd("You have to choose, that choice being the \033[0;37m\e[1mfirst argument\033[0;m\e[m, which set would you like to explore.\n", 1);
	ft_putstr_fd("Your options being: ", 1);
	ft_putstr_fd("\033[0;37m\e[1mMandelbrot", 1);
	ft_putstr_fd(" \033[0;m\e[mor ", 1);	
	ft_putstr_fd("\033[0;37m\e[1mJulia\n", 1);
	ft_putstr_fd("\033[0;mThe other \033[0;37m\e[1m2 values \033[0;m\e[mbelong to the equation that draws both sets.\nThe values can be of type \033[0;37m\e[1m'double' \033[0;m\e[mkeep that in mind.\n", 1);
	ft_putstr_fd("Enjoy :)!\n", 1);
}

void	close_window(void **mlx_win)
{
	mlx_key_hook(*mlx_win, &esc_pressed, NULL);
	mlx_hook(*mlx_win, 17, 0, &top_right, 0);
}

int		top_right(void *param)
{
	(void)param;
	exit(0);
}

int		esc_pressed(int button, void *param)
{
	(void)param;
	if (button == 27)
		exit(0);
	return (1);
}

void	start_window(void **mlx_ptr, void **mlx_win, char *win_name)
{
	*mlx_ptr = mlx_init();
	if (!*mlx_ptr)
		ft_putstr_fd("Error initializing the Minilbx Lib.", 2);
	*mlx_win = mlx_new_window(*mlx_ptr, WIDTH, HEIGHT, win_name);
	if (!*mlx_win)
		ft_putstr_fd("Something wrong when creating the window.", 2);
}