/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:28:12 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/21 16:27:00 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_list *node, t_list **stack, char c)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack);
	if (node->index <= (size / 2))
	{
		i = 0;
		while (i++ < node->index)
			rotate(stack, c);
	}
	else
	{
		i = size;
		while (i-- > node->index)
			reverse_rotate(stack, c);
	}
}

static void	rotate_both(t_list *node, t_list *target, \
						t_list **from_stack, t_list **to_stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < node->index && j++ < target->index)
	{
		rotate(from_stack, ' ');
		rotate(to_stack, ' ');
		ft_printf("rr\n");
	}
}

static void	reverse_rotate_both(t_list *node, t_list *target, \
						t_list **from_stack, t_list **to_stack)
{
	int	i;
	int	j;

	i = ft_lstsize(*from_stack);
	j = ft_lstsize(*to_stack);
	while (i-- > node->index && j-- > target->index)
	{
		reverse_rotate(from_stack, ' ');
		reverse_rotate(to_stack, ' ');
		ft_printf("rrr\n");
	}
}

static void	bring_both_to_top(t_list *node, t_list *target, \
						t_list **from_stack, t_list **to_stack)
{
	int	from_size;
	int	to_size;

	from_size = ft_lstsize(*from_stack) / 2;
	to_size = ft_lstsize(*to_stack) / 2;
	if (node->index <= from_size && target->index <= to_size)
		rotate_both(node, target, from_stack, to_stack);
	else if (node->index > from_size && target->index > to_size)
		reverse_rotate_both(node, target, from_stack, to_stack);
}

void	push_cheapest(t_list *node, t_list *target, \
					t_list **from_stack, t_list **to_stack)
{
	int	from_size;
	int	to_size;

	from_size = ft_lstsize(*from_stack) / 2;
	to_size = ft_lstsize(*to_stack) / 2;
	if ((node->index > from_size && target->index > to_size) || \
		(node->index <= from_size && target->index <= to_size))
	{
		bring_both_to_top(node, target, from_stack, to_stack);
		set_index(from_stack);
		set_index(to_stack);
		bring_to_top(node, from_stack, 'b');
		bring_to_top(target, to_stack, 'a');
	}
	else
	{
		bring_to_top(node, from_stack, 'b');
		bring_to_top(target, to_stack, 'a');
	}
	push(to_stack, from_stack, 'a');
}
