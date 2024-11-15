/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:02:51 by jose-ara          #+#    #+#             */
/*   Updated: 2024/10/08 20:19:44 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf_nodes	*new_node(char c, int (*func)(va_list))
{
	t_printf_nodes	*new_node;

	new_node = (t_printf_nodes *)ft_calloc(1, sizeof(t_printf_nodes));
	if (!new_node)
		return (NULL);
	new_node->iden = c;
	new_node->func = func;
	new_node->next = NULL;
	return (new_node);
}

static void	add_node_end(t_printf_nodes *n1, t_printf_nodes *n2)
{
	if (!n1 || !n2)
		return ;
	while (n1->next)
		n1 = n1->next;
	n1->next = n2;
}

int	ft_select_func(t_printf_nodes **list_head, char c, va_list args)
{
	t_printf_nodes	*aux;

	if (!list_head || !(*list_head))
		return (0);
	aux = *list_head;
	while (aux->iden != c && aux->next)
		aux = aux->next;
	return (aux->func(args));
}

void	free_list_printf(t_printf_nodes **list_head)
{
	t_printf_nodes	*aux;

	if (!list_head || !(*list_head))
		return ;
	while (*list_head)
	{
		aux = *list_head;
		*list_head = (*list_head)->next;
		free(aux);
	}
	free(list_head);
}

t_printf_nodes	**init_printf(void)
{
	t_printf_nodes	**list_head;

	list_head = (t_printf_nodes **)ft_calloc(1, sizeof(t_printf_nodes *));
	if (!list_head)
		return (NULL);
	*list_head = new_node('c', ft_print_char);
	add_node_end(*list_head, new_node('s', ft_print_str));
	add_node_end(*list_head, new_node('p', ft_print_hexadecimal_pointer));
	add_node_end(*list_head, new_node('d', ft_print_int));
	add_node_end(*list_head, new_node('i', ft_print_int));
	add_node_end(*list_head, new_node('u', ft_print_unsigned_int));
	add_node_end(*list_head, new_node('x', ft_print_hexadecimal_lower));
	add_node_end(*list_head, new_node('X', ft_print_hexadecimal_upper));
	return (list_head);
}
