/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:39:45 by jose-ara          #+#    #+#             */
/*   Updated: 2024/11/12 20:05:04 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_info(char const *s, va_list args,
		t_printf_nodes **list_head)
{
	int	cont;

	cont = 0;
	while (*s)
	{
		if (!ft_strncmp(s, "%%", 2))
		{
			write(1, "%", 1);
			cont++;
			s++;
		}
		else if (*s == '%')
		{
			cont += ft_select_func(list_head, s[1], args);
			s++;
		}
		else
		{
			write(1, s, 1);
			cont++;
		}
		s++;
	}
	return (cont);
}

int	ft_printf(char const *s, ...)
{
	va_list			args;
	int				cont;
	t_printf_nodes	**list_head;

	list_head = init_printf();
	va_start(args, s);
	cont = ft_print_info(s, args, list_head);
	va_end(args);
	free_list_printf(list_head);
	return (cont);
}
/*
int main() {
    char c = 'A';
    char *str = "Hola, mundo";
    void *ptr = &str;
    int num_decimal = 42;
    unsigned int num_unsigned = 42;
    //int num_hex = 255;

    //Comparar printf y ft_printf

    // %c: Imprimir un solo carácter
    printf("Original printf - Carácter: %c\n", c);
    ft_printf("ft_printf - Carácter: %c\n", c);
    printf("\n");

    // %s: Imprimir una string
    printf("Original printf - Cadena: %s\n", str);
    ft_printf("ft_printf - Cadena: %s\n", str);
    printf("\n");

    // %p: Imprimir un puntero en formato hexadecimal
    printf("Original printf - Puntero: %p\n", ptr);
    ft_printf("ft_printf - Puntero: %p\n", ptr);
    printf("\n");

    // %d: Imprimir un número decimal (base 10)
    printf("Original printf - Decimal: %d\n", num_decimal);
    ft_printf("ft_printf - Decimal: %d\n", num_decimal);
    printf("\n");

    // %i: Imprimir un entero en base 10
    printf("Original printf - Entero: %i\n", num_decimal);
    ft_printf("ft_printf - Entero: %i\n", num_decimal);
    printf("\n");

    // %u: Imprimir un número decimal sin signo
    printf("Original printf - Unsigned: %u\n", num_unsigned);
    ft_printf("ft_printf - Unsigned: %u\n", num_unsigned);
    printf("\n");

    // %x: Imprimir un número hexadecimal en minúsculas
    printf("Original printf - Hexadecimal minúsculas: %lx\n", LONG_MAX);
    ft_printf("ft_printf - Hexadecimal minúsculas: %x\n", LONG_MAX);
    printf("\n");

    // %X: Imprimir un número hexadecimal en mayúsculas
    printf("Original printf - Hexadecimal mayúsculas: %lX\n", LONG_MIN);
    ft_printf("ft_printf - Hexadecimal mayúsculas: %X\n", LONG_MIN);
    printf("\n");

    // %%: Imprimir el símbolo del porcentaje
    printf("Original printf - Porcentaje: %%\n");
    ft_printf("ft_printf - Porcentaje: %%\n");
    printf("\n");

    return 0;
}
*/
