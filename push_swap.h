/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:47:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/15 17:21:17 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/getnextline.h"

// Initializing and stack utils
void    init_stack(int argc, char **argv, t_list **stack);
void	empty_stack(t_list **stack);
void	set_index(t_list **stack);
void	print_stack(t_list **head);

// Algorithm
void    sort_three(t_list **stack);
void    sort_five(t_list **stack_a, t_list **stack_b);
void    sort_all(t_list **stack_a, t_list **stack_b);
t_list	*find_min(t_list* stack);
t_list	*find_max(t_list* stack);
t_list  *find_target_b(t_list *node, t_list **stack);
t_list  *find_target_a(t_list *node, t_list **stack);
int     calc_cost(t_list *node, t_list *target);
void    push_cheapest(t_list *node, t_list *target, t_list **stack_a, t_list **stack_b);

// Operations
void	swap(t_list **stack);
void	push(t_list **to_s, t_list **from_s);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif
