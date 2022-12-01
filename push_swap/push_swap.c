/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:25:24 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/30 20:56:09 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
                Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
                Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
                Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
                Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
                The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
                The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
                The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
                The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
int main(int args, char *argv[])
{
    p_stack *a;
    int i;

    i = 0;
    a = create_arr(argv, (args - 1));
	printf("Stack A: \n");
    while (i < (args - 1))
    	printf("Número %d :%d\n", i, a->array[i++]);
}