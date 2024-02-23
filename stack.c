/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:19:01 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/21 16:25:52 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	fill_stack(char **numbers, t_list **stack)
{
	t_list	*new;
	int		*temp;
	int		i;

	*stack = NULL;
	i = 0;
	while (numbers[i])
	{
		temp = (int *)malloc(sizeof(int));
		*temp = ft_atoi(numbers[i]);
		new = ft_lstnew(temp);
		ft_lstadd_back(stack, new);
		i++;
	}
	set_index(stack);
}

void	print_stack(t_list **head)
{
	t_list	*temp;

	ft_printf("\n------- Stack ------\n");
	temp = *head;
	while (temp)
	{
		if (temp->content)
			ft_printf("(%i) ", *(int *)temp->content);
		else
			ft_printf("(null) ");
		temp = temp->next;
	}
	ft_printf("\n--------------------\n");
}
