/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:21:54 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/10 22:20:57 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ONLY_MINUS "-"

//Actions available
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

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
int		len_dec(int n);

t_stack	*create_arr(char **args, int size);

//lets_sort
void	lets_sort(int *copy_arr, t_stack *a, t_stack *b);

//sort normal
int		*copy_stack(t_stack *stack);
void	proper_sort(int *tab, int size);

//write_term
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);

//max&min
int		max(t_stack *stack);
int		min(t_stack *stack);
int		mid_sorted(int *array, int size);

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
void	*ft_calloc(size_t nitems, size_t size);

//sort_complex
t_stack	*duplicate_list(t_stack *a);
t_stack	*init(t_stack *a);
void	sort_with_radix(t_stack *dup, t_stack *b);
int		compare_stack(int *array, t_stack *stack);

//create_arr
int		check_duplicates(char **argv, int size);
int		check_int_value(char **argv);
int		check_arr(char **argv);
int		check_only_minus(char **argv);

#endif
