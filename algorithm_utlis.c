/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:17:55 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/16 14:05:09 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list* stack)
{
	int		min;
	int		temp;
	t_list	*node;
	t_list	*min_node;

	node = stack;
	min = *(int*)node->content;
	min_node = node;
	while (node)
	{
		temp = *(int*)node->content;
		if (temp < min)
		{
			min = temp;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

t_list	*find_max(t_list* stack)
{
	int		max;
	int		temp;
	t_list	*node;
	t_list	*max_node;

	node = stack;
	max = *(int*)node->content;
	max_node = node;
	while (node)
	{
		temp = *(int*)node->content;
		if (temp > max)
		{
			max = temp;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

t_list  *find_target_b(t_list *node, t_list **stack)
{
	t_list  *temp;
	t_list  *target;

	temp = *stack;
	target = *stack;
	while (temp)
	{
		if (temp->content)
		{
			if ((*(int*)temp->content < *(int*)node->content) && \
				(*(int*)temp->content > *(int*)target->content))
				target = temp;
		}
		temp = temp->next;
	}
	if (!target)
		target = find_max(*stack);
	return (target);
}

t_list  *find_target_a(t_list *node, t_list **stack)
{
	t_list  *temp;
	t_list  *target;

	temp = *stack;
	target = *stack;
	while (temp)
	{
		if (temp->content)
		{
			if (*(int*)temp->content > *(int*)node->content && \
				*(int*)temp->content < *(int*)target->content)
				target = temp;
		}
		temp = temp->next;
	}
	if (!target)
		target = find_min(*stack);
	return (target);
}

int calc_cost(t_list *node, t_list *target)
{
	int cost;

	cost = node->index + target->index + 1;
	return (cost);
}

void    push_cheapest(t_list *node, t_list *target, t_list **from_stack, t_list **to_stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < node->index && j < target->index)
	{
		rotate(from_stack);
		rotate(to_stack);
		ft_printf("rr\n");
		i++;
		j++;
	}
	while (i < node->index)
	{
		rotate(from_stack);
		ft_printf("ra\n");
		i++;
	}
		while (j < target->index)
	{
		rotate(to_stack);
		ft_printf("rb\n");
		j++;
	}
	push(to_stack, from_stack);
	ft_printf("pb\n");
}
