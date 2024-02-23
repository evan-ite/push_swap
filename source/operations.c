/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:38:14 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/23 12:02:35 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list	*first;
	t_list	*second;

	first = (*stack)->next;
	second = *stack;
	second->next = first->next;
	first->next = second;
	*stack = first;
	if (c != ' ')
		ft_printf("s%c\n", c);
}

void	push(t_list **to_stack, t_list **from_stack, char c)
{
	t_list	*temp;

	temp = (*from_stack)->next;
	(*from_stack)->next = *to_stack;
	*to_stack = *from_stack;
	*from_stack = temp;
	if (c != ' ')
		ft_printf("p%c\n", c);
}

void	rotate(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*node;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	node = *stack;
	*stack = temp;
	ft_lstadd_back(stack, node);
	if (c != ' ')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*second_last;
	t_list	*last;

	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	second_last = temp;
	last = temp->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c != ' ')
		ft_printf("rr%c\n", c);
}
