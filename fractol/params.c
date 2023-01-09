/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:28:42 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:12:52 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params *create_params(void *mlx_ptr, void *mlx_win, double zoom)
{
	t_params *params;

	params = malloc(sizeof(t_params));
	params->mlx_ptr = mlx_ptr;
	params->mlx_win = mlx_win;
	params->zoom = zoom;

	return (params);
}