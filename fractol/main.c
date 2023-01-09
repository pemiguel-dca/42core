/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:32:40 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:12:14 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	confirm_params(int n_params, char **argv)
{
	int	i;
	int	j;
	int	valid;

	valid = 0;
	if (n_params != 3)
		return (1);
	if (!ft_strcmp(argv[1], MANDELBROT) || !ft_strcmp(argv[1], JULIA))
		valid = 0;
	else
		valid = 1;
	j = 1;
	i = 0;
	while (argv[++j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_strchr(DEC_BASE, argv[j][i++]))
				return (1);
		}
	}
	return (valid);
}

int main(int argc, char *argv[])
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		*win_name;
	double		zoom;
	t_params	*params;

	zoom = 1.0;
	mlx_ptr = 0;
	mlx_win = 0;
	if (argc == 4 && !confirm_params((argc - 1), argv))
	{
		win_name = ft_strjoin(argv[1], " Set");
		start_window(&mlx_ptr, &mlx_win, win_name);
		close_window(&mlx_win);
		if (!ft_strcmp(argv[1], JULIA))
		{
			draw_julia(&mlx_ptr, &mlx_win, zoom);
			params = create_params(mlx_ptr, mlx_win, zoom);
			printf("%p\n", params);
			//mlx_hook(mlx_win, 6, 1 << 6, &mouse_zoom, (void *)params);
			//does not recognize the adress of params!!!
		}
		mlx_loop(mlx_ptr);
	}
	else
		requirements();
	return (0);
}