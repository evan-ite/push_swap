/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/02/14 15:52:14 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_list **stack)
{
    t_list  *a;
    t_list  *b;
    t_list  *c;

    a = *stack;
    b = (*stack)->next;
    c = b->next;
    if (*(int*)a->content > *(int*)b->content)
    {
        swap(stack);
        ft_printf("sa\n");
    }
    a = *stack;
    b = (*stack)->next;
    c = b->next;
    if (*(int*)c->content < *(int*)a->content)
    {
        reverse_rotate(stack);
        ft_printf("rra\n");
    }
    a = *stack;
    b = (*stack)->next;
    c = b->next;
    if (*(int*)b->content > *(int*)c->content)
    {
        reverse_rotate(stack);
        ft_printf("rra\n");
        swap(stack);
        ft_printf("sa\n");
    }
}