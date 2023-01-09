/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:32:40 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:12:42 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int key, int x, int y, void *params)
{
	t_params	*p;
	double		max_zoom;
	
	(void)x;
	(void)y;
	p = (t_params *)params;
	printf("%p\n", p);
	max_zoom = 10.0;
	if (key == 4 && p->zoom < max_zoom)
		p->zoom *= 1.2;
	else if (key == 5)
		p->zoom /= 1.2;
	draw_julia(p->mlx_ptr, p->mlx_win, p->zoom);
	return (0);
}

int		max_iterations(complex z, complex c)
{
	int		i;
	double	point;
	int		color;
	
	i = -1;
	point = 0;
	color = 0;
	while (++i < MAX_ITERATIONS)
	{
		point = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = point;
		if (z.r * z.r + z.i * z.i > 4)//cor fora do plano complexo
			return (i);
	}
	color = i / 255;
	return (color);
}

void	draw_julia(void **mlx_ptr, void **mlx_win, double zoom)
{
	complex	z;
	complex	c;
	int		x;
	int		y;
	int		color;

	x = -1;
	y = -1;
	c.r = -0.8;
	c.i = 0.156;
	color = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.r = zoom * 2.5 * (x - WIDTH / 2) / (WIDTH / 2);
			z.i = zoom * 1.5 * (y - HEIGHT / 2) / (HEIGHT / 2);
			color = max_iterations(z, c);
			mlx_pixel_put(*mlx_ptr, *mlx_win, x, y, color | (color << 12) | (color << 18));
		}
	}
}
