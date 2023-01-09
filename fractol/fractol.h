/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:33:43 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:13:51 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//bibliotecas necessárias
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

//o ponto pertence à base pois os numéros passados vao ser floats
# define DEC_BASE "0123456789."
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"
//Medidas da janela
# define HEIGHT 600
# define WIDTH 800
# define MAX_ITERATIONS 100

//Estrutura que define cada sigla das equações
//A equação funciona com números complexos, e um número complexo é a soma de um número real com um número imaginário
typedef struct complex
{
    double  r; //real
    double  i; //imaginário
}		complex;

typedef struct {
	void	*mlx_ptr;
	void	*mlx_win;
	double	zoom;
}		t_params;

//utils
int	    ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
int	    ft_strcmp(const char *s1, const char *s2);
void    ft_putstr_fd(char *s, int fd);

//utils2
int     ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

//basics
void	start_window(void **mlx_ptr, void **mlx_win, char *win_name);
void	requirements();
int	    esc_pressed(int button, void *param);
int		top_right(void *param);
void	close_window(void **mlx_win);

//draw
void	draw_julia(void **mlx_ptr, void **mlx_win, double zoom);
int		mouse_zoom(int key, int x, int y, void *param);

//params
t_params	*create_params(void *mlx_ptr, void *mlx_win, double zoom);
#endif