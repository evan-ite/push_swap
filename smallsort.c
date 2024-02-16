/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/16 14:22:56 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    set_abc(t_list **a, t_list **b, t_list **c, t_list **stack)
{
	*a = *stack;
	*b = (*stack)->next;
	*c = (*b)->next;
}

void final_sort(t_list **stack)
{
	t_list	*min;
	int		i;

	min = find_min(*stack);
	if (min->index < (ft_lstsize(*stack) / 2))
	{
		i = 0;
		while (i < min->index)
		{
			rotate(stack);
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		i = ft_lstsize(*stack);
		while (i > min->index)
		{
			reverse_rotate(stack);
			ft_printf("rra\n");
			i--;
		}
	}
}

void    sort_three(t_list **stack)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	t_list	*c = NULL;

	if (ft_lstsize(*stack) < 3)
	{
		if (!(*stack)->next)
			return ;
		if (*(int*)(*stack)->content > *(int*)(*stack)->next->content)
		{
			swap(stack);
			ft_printf("sa\n");
			return ;
		}
		return ;
	}
	set_abc(&a, &b, &c, stack);
	if (*(int*)a->content > *(int*)b->content)
	{
		swap(stack);
		ft_printf("sa\n");
	}
	set_abc(&a, &b, &c, stack);
	if (*(int*)c->content < *(int*)a->content)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	set_abc(&a, &b, &c, stack);
	if (*(int*)b->content > *(int*)c->content)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
		swap(stack);
		ft_printf("sa\n");
	}
}

void    sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;
	int		i;

	while (ft_lstsize(*stack_a) > 3)
	{
		push(stack_b, stack_a);
		ft_printf("pb\n");
	}
	sort_three(stack_a);
	temp_b = *stack_b;
	temp_a = *stack_a;
	while (ft_lstsize(*stack_b) > 1)
	{
		set_index(stack_a);
		while (*(int*)temp_b->content > *(int*)temp_a->content)
			temp_a = temp_a->next;
		if (temp_a->index < (ft_lstsize(*stack_a) / 2))
		{
			i = 0;
			while (i < temp_a->index)
			{
				rotate(stack_a);
				ft_printf("ra\n");
				i++;
			}
		}
		else
		{
			i = ft_lstsize(*stack_a);
			while (i > temp_a->index)
			{
				reverse_rotate(stack_a);
				ft_printf("rra\n");
				i--;
			}
		}
		push(stack_a, stack_b);
		ft_printf("pa\n");
		temp_b = *stack_b;
		temp_a = *stack_a;
	}
	set_index(stack_a);
	final_sort(stack_a);
}
