/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:21:54 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/04 19:10:38 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STD_ERROR 2
# define ONLY_MINUS "-"
//Actions available
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stacks
{
	int				pos_top;
	int				*array;
	unsigned int	size;
}		t_stack;

//helpers
int		ft_atoi(char *str);
int		ft_isdigit(int arg);
size_t	ft_strlen(char *str);

t_stack	*create_arr(char **args, int size);

//sort normal
int		*copy_a(t_stack *a);
void	proper_sort(int *tab, int size);

//str
void	*ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

//max&min
int		max(t_stack *stack);
int		min(t_stack *stack);

//actions
void	swap(int *first, int *second);
void	swap_one_stack(char *name_ac, t_stack *stack, int how_much);
void	rotate_one_stack(char *name_ac, t_stack *stack, int how_much);
void	push_b(char *name_ac, t_stack *a, t_stack *b);
void	push_a(char *name_ac, t_stack *a, t_stack *b);

//actions_2
void	rr_one_stack(char *name_ac, t_stack *stack, int how_much);
void	ss(char *name_ac, t_stack *a, t_stack *b);
void	rr(char *name_ac, t_stack *a, t_stack *b);
void	rrr(char *name_ac, t_stack *a, t_stack *b);

#endif
