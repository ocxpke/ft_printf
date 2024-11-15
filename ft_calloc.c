/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:11:59 by jose-ara          #+#    #+#             */
/*   Updated: 2024/10/10 20:48:27 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void				*ptr;
	void				*cpy_ptr;
	unsigned long int	to_cmp;

	to_cmp = (unsigned long int)nmeb * (unsigned long int)size;
	if (!to_cmp || (to_cmp >= INT_MAX))
		return (malloc(0));
	ptr = malloc((nmeb) * size);
	if (!ptr)
		return (ptr);
	cpy_ptr = ptr;
	while (nmeb--)
	{
		ft_bzero(ptr, size);
		ptr += size;
	}
	return (cpy_ptr);
}
