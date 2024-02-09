/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:46:30 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/09 16:57:35 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**find_min(t_list* stack)
{
	int		min[3]  = {INT_MAX, INT_MAX, INT_MAX};
	int		temp;
	t_list	*node;
	t_list	**min_nodes = (t_list **)malloc(sizeof(t_list *) * 3);
	int		i;

	i = 0;
	while (min_nodes[i])
		min_nodes[i++] = NULL;
	node = stack;
	// min = ft_atoi(node->content);
	// *min_nodes = node;
	while (node)
	{
		temp = ft_atoi(node->content);
		i = 0;
		while (i < 3)
		{
			if (temp < min[i])
			{
				min[i] = temp;
				min_nodes[i] = node;
				break;
			}
			i++;
		}
		node = node->next;
	}
	return (min_nodes);
}


t_list	*find_max(t_list* stack)
{
	int		max;
	int		temp;
	t_list	*node;
	t_list	*max_node;

	node = stack;
	max = ft_atoi(node->content);
	max_node = node;
	while (node)
	{
		if (!node->content)
			break ;
		temp = ft_atoi(node->content);
		if (temp > max)
		{
			max = temp;
			max_node = node;
			break;
		}
		node = node->next;
	}
	return (max_node);
}

void	set_index(t_list **stack)
{
	int		i;
	t_list	*node;

	node = *stack;
	i = 0;
	while (node)
	{
		node->index = i;
		node = node->next;
		i++;
	}
}

int	find_cheapest(t_list **target_nodes, t_list **stack)
{
	int	stack_size;
	int	i;
	int	cheapest;
	int	cheapesti;

	i = 0;
	stack_size = ft_lstsize(*stack);
	cheapest = INT_MAX;
	cheapesti = INT_MAX;
	while (i < 3)
	{
		if (ABS(target_nodes[i]->index, stack_size) < cheapest)
		{
			cheapest = ABS(target_nodes[i]->index, stack_size);
			cheapesti = i;
		}
		i++;
	}
	return (cheapesti);
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	**target;
	t_list	*current;
	int		stack_size;
	int		count;

	count = 0;
	while (*stack_a)
	{
		set_index(stack_a);
		target = find_min(*stack_a);
		current = *stack_a;
		stack_size = ft_lstsize(*stack_a);
		while ((current->index != target[0]->index || \
				current->index != target[1]->index || \
				current->index != target[2]->index) \
				&& stack_size > 1)
		{
			if (target[find_cheapest(target, stack_a)]->index > (stack_size / 2))
			{
				reverse_rotate(stack_a);
				ft_printf("rra\n");
			}
			else
			{
				rotate(stack_a);
				ft_printf("ra\n");
			}
			current = *stack_a;
		}
		push(stack_b, stack_a);
		ft_printf("pb\n");
		count++;
		// print_stack(stack_a);
		// print_stack(stack_b);
	}
	current = *stack_b;
	// Removing NULL from bottom of stack B
	while (current->next->next)
		current = current->next;
	current->next = NULL;
	while (*stack_b)
	{
		set_index(stack_b);
		t_list *target = find_max(*stack_b);
		current = *stack_b;
		stack_size = ft_lstsize(*stack_b);
		while (current->index != target->index && stack_size > 1)
		{
			if (target->index > (stack_size / 2))
			{
				reverse_rotate(stack_b);
				ft_printf("rrb\n");
			}
			else
			{
				rotate(stack_b);
				ft_printf("rb\n");
			}
			current = *stack_b;
		}
		push(stack_a, stack_b);
		ft_printf("pa\n");
		count++;
	}
}
