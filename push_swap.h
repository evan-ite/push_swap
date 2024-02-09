/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:47:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/09 16:43:20 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/getnextline.h"

# define ABS(x, y) ((x) > (y) ? (x) - (y) : (y) - (x))

// Initializing and stack utils
t_list	**init_stack(int argc, char **argv);
t_list	**empty_stack();
void	set_index(t_list **stack);
void	print_stack(t_list **head);

// Algorithm
void	insertion_sort(t_list **stack_a, t_list **stack_b);

// Operations
void	swap(t_list **stack);
void	push(t_list **to_s, t_list **from_s);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif
