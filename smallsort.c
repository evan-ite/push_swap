/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/15 15:56:31 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    set_abc(t_list **a, t_list **b, t_list **c, t_list **stack)
{
    *a = *stack;
    *b = (*stack)->next;
    *c = (*b)->next;
}

void    sort_three(t_list **stack)
{
    t_list  *a = NULL;
    t_list  *b = NULL;
    t_list  *c = NULL;

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
    t_list  *a = NULL;
    t_list  *b = NULL;
    t_list  *c = NULL;
    t_list  *temp;

    while (ft_lstsize(*stack_a) > 3)
    {
        push(stack_b, stack_a);
        ft_printf("pb\n");
    }
    sort_three(stack_a);
    set_abc(&a, &b, &c, stack_a);
    temp = *stack_b;
    while (ft_lstsize(*stack_b) > 1)
    {
        if (*(int*)temp->content < *(int*)a->content)
        {
            push(stack_a, stack_b);
            ft_printf("pa\n");
        }
        else if (*(int*)temp->content > *(int*)c->content)
        {
            push(stack_a, stack_b);
            ft_printf("pa\n");
            rotate(stack_a);
            ft_printf("ra\n");
        }
        else if (*(int*)temp->content < *(int*)b->content)
        {
            push(stack_a, stack_b);
            ft_printf("pa\n");
            swap(stack_a);
            ft_printf("sa\n");
        }
        else if (*(int*)temp->content > *(int*)b->content)
        {
            reverse_rotate(stack_a);
            ft_printf("rra\n");
            push(stack_a, stack_b);
            ft_printf("pa\n");
            rotate(stack_a);
            ft_printf("ra\n");
            rotate(stack_a);
            ft_printf("ra\n");
        }
        temp = *stack_b;
        set_abc(&a, &b, &c, stack_a);
    }
}