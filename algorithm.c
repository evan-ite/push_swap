/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:00:54 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/15 17:23:24 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_a(t_list **stack_a, t_list **stack_b)
{
    int     i;
    int     cheapest;
    int     push_cost;
    t_list  *cheapest_node;
    t_list  *target_node;
    t_list  *temp;
    t_list  *temp_target;

    i = 0;
    while (ft_lstsize(*stack_a) > 3 && i < 2)
    {
        push(stack_b, stack_a);
        ft_printf("pb\n");
        i++;
    }
    cheapest = INT_MAX;
    while (ft_lstsize(*stack_a) > 3)
    {
        set_index(stack_a);
        set_index(stack_b);
        temp = *stack_a;
        while (temp)
        {
            temp_target = find_target_b(temp, stack_b);
            push_cost = calc_cost(temp, temp_target);
            if (push_cost < cheapest)
            {
                cheapest_node = temp;
                cheapest = push_cost;
                target_node = temp_target;
            }
            temp = temp->next;
        }
        push_cheapest(cheapest_node, target_node, stack_a, stack_b);
    }
    sort_three(stack_a);
}

static void    sort_b(t_list **stack_a, t_list **stack_b)
{
    int     cheapest;
    int     push_cost;
    t_list  *cheapest_node;
    t_list  *target_node;
    t_list  *temp;
    t_list  *temp_target;

    while (ft_lstsize(*stack_b) > 1)
    {
        set_index(stack_a);
        set_index(stack_b);
        temp = *stack_a;
        while (temp)
        {
            temp_target = find_target_a(temp, stack_b);
            push_cost = calc_cost(temp, temp_target);
            if (push_cost < cheapest)
            {
                cheapest_node = temp;
                cheapest = push_cost;
                target_node = temp_target;
            }
            temp = temp->next;
        }
        push_cheapest(cheapest_node, target_node, stack_a, stack_b);
    }
}

void    sort_all(t_list **stack_a, t_list **stack_b)
{
    // t_list  *min;

    sort_a(stack_a, stack_b);
    sort_b(stack_a, stack_b);
    // min = find_min(*stack_a);
    // rotate or reverse rotate depending on min->index
}