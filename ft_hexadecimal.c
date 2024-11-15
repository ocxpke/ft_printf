/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:43:50 by jose-ara          #+#    #+#             */
/*   Updated: 2024/10/07 21:39:25 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_num_len(unsigned long long int num)
{
	size_t	cont;

	cont = 0;
	if (!num)
		return (1);
	while (num > 0)
	{
		num /= 16;
		cont++;
	}
	return (cont);
}

char	*ft_pointer_to_hex(uintptr_t int_ptr)
{
	return (ft_to_hex((unsigned long int)int_ptr, 0));
}

char	*ft_to_hex(unsigned long int num, int mode)
{
	char	*base;
	char	*ret;
	size_t	cont;

	if (!mode)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	cont = hex_num_len(num);
	ret = (char *)ft_calloc(1, cont + 1);
	if (!ret)
		return (NULL);
	ret[cont] = 0;
	if (!num)
		ret[--cont] = '0';
	while (num > 0)
	{
		cont--;
		ret[cont] = base[num % 16];
		num /= 16;
	}
	return (ret);
}

int	ft_print_hexadecimal_lower(va_list args)
{
	char	*str;
	int		cont;

	str = ft_to_hex(va_arg(args, unsigned int), 0);
	if (!str)
		return (0);
	cont = ft_strlen(str);
	write(1, str, cont);
	free(str);
	return (cont);
}

int	ft_print_hexadecimal_upper(va_list args)
{
	char	*str;
	int		cont;

	str = ft_to_hex(va_arg(args, unsigned int), 1);
	if (!str)
		return (0);
	cont = ft_strlen(str);
	write(1, str, cont);
	free(str);
	return (cont);
}
