/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:33 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/21 19:41:11 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

# define MIN_INT -2147483648
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

/* Funcionamento da va_list
type va_arg(
   va_list arg_ptr,
   type
);
void va_copy(
   va_list dest,
   va_list src
); // (ISO C99 and later)
void va_end(
   va_list arg_ptr
);
void va_start(
   va_list arg_ptr,
   prev_param
); // (ANSI C89 and later)
void va_start(
   arg_ptr
);  // (deprecated Pre-ANSI C89 standardization version)
*/
int	print_hexs(int n);
int	ft_printf(char const *format, ...);

size_t	ft_putnbr(size_t n);

int	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_atoi(const char *str);
char	*ft_itoa(int n);

int	print(va_list args, char c);
#endif
