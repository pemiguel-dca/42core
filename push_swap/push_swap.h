/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:21:54 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/03 17:59:27 by pemiguel         ###   ########.fr       */
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
	int				*array;
	unsigned int	size;
}		t_stack;

//helpers
int		ft_atoi(char *str);
int		ft_isdigit(int arg);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nitems, size_t size);

t_stack	*create_arr(char **args, int size);

//sort normal
int		*copy_a(t_stack *a);
void	proper_sort(int *tab, int size);

//str
void	*ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

//max&min
int	max(t_stack *stack);
int	min(t_stack *stack);

//actions
void	swap_one_stacks(char *name_ac, t_stack *stack);
void	rotate_one_stack(char *name_ac, t_stack *stack);
#endif
