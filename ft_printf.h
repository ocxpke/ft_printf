/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-ara < jose-ara@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:37:41 by jose-ara          #+#    #+#             */
/*   Updated: 2024/11/12 20:01:35 by jose-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * Imports we need for our functions
 */
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * Structure used to iterate and select the function to execute
 */
typedef struct s_printf_nodes
{
	char					iden;
	int						(*func)(va_list args);
	struct s_printf_nodes	*next;
}							t_printf_nodes;

/**		_________________________
 *		|						|
 *		|	FT_PRINTF.C FILE	|
 *		|_______________________|
 */

/**
 * @brief Funtion that replicates the original printf
 *
 * @param s Origin str to read from and print information
 * @param ... Variadic parameters passed
 *
 * @return The number of character written
 */
int							ft_printf(char const *s,
								...) __attribute__((format(printf, 1, 2)));

/**		_____________________________
 *		|							|
 *		|	FT_PRINTF_FUNC.C FILE	|
 *		|___________________________|
 */

/**
 * @brief Prints an unique char
 *
 * @param args The variadic parameter that corresponds
 *
 * @return Always 1
 */
int							ft_print_char(va_list args);

/**
 * @brief Prints an entire array of characters
 *
 * @param args The variadic parameter that corresponds
 *
 * @return Strlen of the string
 */
int							ft_print_str(va_list args);

/**
 * @brief Prints an integer
 *
 * @param args The variadic parameter that corresponds
 *
 * @return The length of the integer
 */
int							ft_print_int(va_list args);

/**
 * @brief Prints an unsigned integer
 *
 * @param args The variadic parameter that corresponds
 *
 * @return The length of the unsigned integer
 */
int							ft_print_unsigned_int(va_list args);

/**
 * @brief Prints the memory direction of a pointer in low hexadecimal
 *
 * @param args The variadic parameter that corresponds
 *
 * @return The length of the pointer written
 */
int							ft_print_hexadecimal_pointer(va_list args);

/**		_____________________________
 *		|							|
 *		|	FT_HEXADECIMAL.C FILE	|
 *		|___________________________|
 */

/**
 * @brief Prints the hexadecimal value of an integer in low characters
 *
 * @param args The variadic parameter that corresponds
 *
 * @return The length of the hexadecimal value written
 */
int							ft_print_hexadecimal_lower(va_list args);

/**
 * @brief Prints the hexadecimal value of an integer in upper characters
 *
 * @param args The variadic parameter that corresponds
 *
 * @return The length of the hexadecimal value written
 */
int							ft_print_hexadecimal_upper(va_list args);

/**
 * @brief Makes a special call for ft_to_hex() for casting and printing
 * the hex value
 *
 * @param int_ptr The integer value of the pointer
 *
 * @return The string that has been done by ft_to_hex
 */
char						*ft_pointer_to_hex(uintptr_t int_ptr);

/**
 * @brief Casts the recieved unsigned long int into and hexadecimal value,
 * mode(0) -> lower, mode(1) -> upper
 *
 * @param num Unsigned long integer number received
 * @param mode Used for knowing if its an upper or lower hex
 *
 * @return The hexadecimal value
 */
char						*ft_to_hex(unsigned long int num, int mode);

/**		_____________________________
 *		|							|
 *		|	FT_LIST_MANAGER.C FILE	|
 *		|___________________________|
 */

/**
 * @brief Initialize a pointer to the head of a list with all chars
 * and func related
 *
 * @return The memory location of the head of the list
 */
t_printf_nodes				**init_printf(void);

/**
 * @brief Makes a free for each component of the list included
 * the head of the list pointer
 *
 * @param list_head The pointer of the list_head
 *
 * @return Void
 */
void						free_list_printf(t_printf_nodes **list_head);

/**
 * @brief Iterates over the list to find which func to use
 *
 * @param list_head The pointer of the list_head
 * @param c Char used for selecting the function to use
 * @param args The variadic parameter that corresponds
 *
 * @return The value returned of the function selected
 */
int							ft_select_func(t_printf_nodes **list_head, char c,
								va_list args);

void						*ft_calloc(size_t nmeb, size_t size);
size_t						ft_strlen(const char *s);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
char						*ft_uitoa(unsigned int n);
char						*ft_itoa(int n);
void						ft_bzero(void *s, size_t n);
#endif
