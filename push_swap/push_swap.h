/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:21:54 by pemiguel          #+#    #+#             */
/*   Updated: 2022/12/01 14:26:24 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STD_ERROR 2

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
    int		*array;
    unsigned int	size;
}       p_stack;

int		ft_atoi(char *str);
int		ft_isdigit(int arg);
size_t	ft_strlen(char *str);

p_stack	*create_arr(char **args, int size);
#endif
