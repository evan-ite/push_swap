/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:38:14 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/14 15:50:02 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = (*stack)->next;
	second = *stack;
	second->next = first->next;
	first->next = second;
	*stack = first;
}

void	push(t_list **to_stack, t_list **from_stack)
{
	t_list	*temp;

	temp = (*from_stack)->next;
	(*from_stack)->next = *to_stack;
	*to_stack = *from_stack;
	*from_stack = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*node;

	temp = (*stack)->next;
	node = *stack;
	*stack = temp;
	ft_lstadd_back(stack, node);
}

void	reverse_rotate(t_list **stack)
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
}
