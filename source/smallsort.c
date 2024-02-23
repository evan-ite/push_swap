/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/23 12:02:42 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_abc(t_list **a, t_list **b, t_list **c, t_list **stack)
{
	*a = *stack;
	*b = (*stack)->next;
	*c = (*b)->next;
}

static void	below_three(t_list **stack)
{
	if (!(*stack)->next)
		return ;
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
		swap(stack, 'a');
	return ;
}

void	final_sort(t_list **stack)
{
	t_list	*min;
	int		i;

	min = find_min(*stack);
	if (min->index < (ft_lstsize(*stack) / 2))
	{
		i = 0;
		while (i++ < min->index)
			rotate(stack, 'a');
	}
	else
	{
		i = ft_lstsize(*stack);
		while (i-- > min->index)
			reverse_rotate(stack, 'a');
	}
}

void	sort_three(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (ft_lstsize(*stack) < 3)
	{
		below_three(stack);
		return ;
	}
	a = NULL;
	b = NULL;
	c = NULL;
	set_abc(&a, &b, &c, stack);
	if (*(int *)a->content > *(int *)b->content)
		swap(stack, 'a');
	set_abc(&a, &b, &c, stack);
	if (*(int *)c->content < *(int *)a->content)
		reverse_rotate(stack, 'a');
	set_abc(&a, &b, &c, stack);
	if (*(int *)b->content > *(int *)c->content)
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push(stack_b, stack_a, 'b');
	sort_three(stack_a);
	while (*stack_b)
		sort_b(stack_a, stack_b);
	set_index(stack_a);
	final_sort(stack_a);
}
