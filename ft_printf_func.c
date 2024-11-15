/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:36:51 by jose-ara          #+#    #+#             */
/*   Updated: 2024/10/07 21:36:37 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list args)
{
	int		ret;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = ft_strlen(str);
	write(1, str, ret);
	return (ret);
}

int	ft_print_int(va_list args)
{
	char	*str;
	int		ret;

	if (!args)
		return (0);
	str = ft_itoa(va_arg(args, int));
	ret = (int)ft_strlen(str);
	write(1, str, ret);
	free(str);
	return (ret);
}

int	ft_print_unsigned_int(va_list args)
{
	char			*str;
	int				ret;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	str = ft_uitoa(num);
	ret = (int)ft_strlen(str);
	write(1, str, ret);
	free(str);
	return (ret);
}

int	ft_print_hexadecimal_pointer(va_list args)
{
	char	*ret;
	void	*ptr;
	int		cont;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ret = ft_pointer_to_hex((uintptr_t)ptr);
	cont = ft_strlen(ret);
	write(1, "0x", 2);
	write(1, ret, cont);
	free(ret);
	return (cont + 2);
}
