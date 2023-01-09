/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:21:54 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/09 13:06:39 by pemiguel         ###   ########.fr       */
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
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_isdigit(int arg);
int		ft_get_index(int *str1, int *str2);
int		ft_memcmp(void *str1, void *str2, size_t n);

t_stack	*create_arr(char **args, int size);

//lets_sort
void	lets_sort(int *array, t_stack *a, t_stack *b);

//sort normal
int		*copy_stack(t_stack *stack);
void	proper_sort(int *tab, int size);
void	proper_sort_b(int *tab, int size);

//str
void	*ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

//max&min
int		max(t_stack *stack);
int		min(t_stack *stack);
int		mid_sorted(int *array, int size);
int		mid_sorted_for_b(int *array, int size);
int		find_pos_beg(int nb, t_stack *stack);
int		find_pos_end(int nb, t_stack *stack);

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

//exception
void	when_size_3(t_stack *a);

//new idea
t_stack	*duplicate_list(t_stack *a);
t_stack	*init(t_stack *a);
void	sort_with_radix(t_stack *dup, t_stack *b);
int		compare_stack(int *array, t_stack *stack);

int		check_duplicates(char **argv, int size);
int		check_int_value(char **argv);
int		check_arr(char **argv);
#endif
