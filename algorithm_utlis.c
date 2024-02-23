/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:17:55 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/21 16:23:40 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	average(t_list *stack)
{
	long	sum;
	t_list	*temp;

	temp = stack;
	sum = 0;
	while (temp)
	{
		sum += *(int *)temp->content;
		temp = temp->next;
	}
	return (sum / ft_lstsize(stack));
}

t_list	*find_min(t_list *stack)
{
	int		min;
	int		temp;
	t_list	*node;
	t_list	*min_node;

	node = stack;
	min = *(int *)node->content;
	min_node = node;
	while (node)
	{
		temp = *(int *)node->content;
		if (temp < min)
		{
			min = temp;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

t_list	*find_max(t_list *stack)
{
	int		max;
	int		temp;
	t_list	*node;
	t_list	*max_node;

	node = stack;
	max = *(int *)node->content;
	max_node = node;
	while (node)
	{
		temp = *(int *)node->content;
		if (temp > max)
		{
			max = temp;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

t_list	*find_target(t_list *node, t_list **stack)
{
	t_list	*temp;
	t_list	*target;

	temp = *stack;
	target = find_max(*stack);
	if (*(int *)node->content > *(int *)target->content)
		return (find_min(*stack));
	while (temp)
	{
		if (temp->content)
		{
			if (*(int *)temp->content > *(int *)node->content && \
				*(int *)temp->content < *(int *)target->content)
				target = temp;
		}
		temp = temp->next;
	}
	return (target);
}

int	calc_cost(t_list *node, t_list *target, \
			t_list **stack_node, t_list **stack_tar)
{
	int	cost;
	int	size_stack_node;
	int	size_stack_tar;

	size_stack_node = (ft_lstsize(*stack_node) / 2);
	size_stack_tar = (ft_lstsize(*stack_tar) / 2);
	cost = 0;
	if (node->index <= size_stack_node)
		cost += node->index;
	else if (node->index > size_stack_node)
		cost += ft_lstsize(*stack_node) - node->index - 1;
	if (target->index <= size_stack_tar)
		cost += target->index;
	else if (target->index > size_stack_tar)
		cost += ft_lstsize(*stack_tar) - target->index - 1;
	return (cost);
}
