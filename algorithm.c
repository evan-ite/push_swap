/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:00:54 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/21 15:49:29 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if (*(int *)(*stack_a)->content < average(*stack_a))
			push(stack_b, stack_a, 'b');
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
}

void	sort_b(t_list **stack_a, t_list **stack_b)
{
	int		cheapest;
	t_list	*cheapest_node;
	t_list	*temp;
	t_list	*target_node;

	while (ft_lstsize(*stack_b) > 0)
	{
		set_index(stack_a);
		set_index(stack_b);
		temp = *stack_b;
		cheapest = INT_MAX;
		while (temp)
		{
			temp->target = find_target(temp, stack_a);
			temp->push_cost = calc_cost(temp, temp->target, stack_b, stack_a);
			if (temp->push_cost < cheapest)
			{
				cheapest_node = temp;
				cheapest = temp->push_cost;
				target_node = temp->target;
			}
			temp = temp->next;
		}
		push_cheapest(cheapest_node, target_node, stack_b, stack_a);
	}
}

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	sort_a(stack_a, stack_b);
	sort_b(stack_a, stack_b);
	set_index(stack_a);
	final_sort(stack_a);
}
