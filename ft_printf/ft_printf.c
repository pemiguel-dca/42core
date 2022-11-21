/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:27 by pemiguel          #+#    #+#             */
/*   Updated: 2022/11/21 19:41:10 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return Value
If successful, the total number of characters written is returned.
On failure, a negative number is returned.
*/

#include "ft_printf.h"

int	print(va_list args, char c) //retorna a string inteira para depois calcular o numero de bytes
{
	size_t	total_length;

	total_length = 0;
	if (c == 's') //string of characters
		ft_putstr(va_arg(args, char *));
	else if (c == 'c') //character
		ft_putchar(va_arg(args, int));
	else if (c == 'd') //decimal
		ft_putnbr(va_arg(args, int));
	else if (c == 'i') //inteiro, nao tem ','
		va_arg(args, int);
	else if (c == 'p') //pointer adress
		va_arg(args, void *);
	else if (c == 'x') //Unsigned hexadecimal integer
		va_arg(args, char *);
	else if (c == 'X') //Unsigned hexadecimal integer (capital letters)
		va_arg(args, char *);
	else if (c == 'u') //Unsigned decimal integer
		va_arg(args, char *);
}

int ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	size_t	total_length;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%') // se ele encontrar o "%", verifica o proximo
		{
			i++; //avancamos para o proximo caracter. que e o que interessa
			total_length = print(args, format[i]); //somamos o resultado da length ao total
		}
		else
			total_length = ft_putchar(format[i]);
		i++;
	}
	return (total_length);
}

int main()
{
	/*
	printf("        %s\n", "ola"); //res = "        ola", ou seja contar com os espaços no formato
	printf("%s \n%s \n", "xau","xau"); //se tiver mais de um %s, temos de adicionar uma virgula
								 //sem a virgula nao é valido pois "% = 2" e strings = 1
	printf("\n"); //valido apesar de segundo argumento = 0.
	printf("\t"); //valido tambem
	printf("%s", "ola"); //invalido nao pode haver espaços entre o tipo que vai dar print
								  //e o '%'
	printf("%std", "ola");
	*/
	//printf("%d" ,number_args("%s %s"));
	printf("%%");
	//ft_printf("Isto é uma string %s", "ola esta tudo bem?");
}
