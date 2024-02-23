/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:47:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/22 12:53:19 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/getnextline.h"

// Input check
char	**check_args(int argc, char **argv);
int		check_sorted(t_list **stack);

// Initializing stack and utils
void	fill_stack(char **numbers, t_list **stack);
void	set_index(t_list **stack);
void	print_stack(t_list **head);
void	free_numbers(char **numbers);

// Algorithm
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_all(t_list **stack_a, t_list **stack_b);
void	sort_b(t_list **stack_a, t_list **stack_b);
void	final_sort(t_list **stack);

// Algorithm utils
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*find_target(t_list *node, t_list **stack);
void	bring_to_top(t_list *node, t_list **stack, char c);
int		average(t_list *stack);
int		calc_cost(t_list *node, t_list *target, \
				t_list **stack_node, t_list **stack_tar);
void	push_cheapest(t_list *node, t_list *target, \
				t_list **from_stack, t_list **to_stack);

// Operations
void	swap(t_list **stack, char c);
void	push(t_list **to_s, t_list **from_s, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);

#endif
