/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:19:01 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/14 14:57:18 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(char **numbers, t_list **stack)
{
	t_list	*new;
	int		i;

	*stack = NULL;
	i = 0;
	while (numbers[i])
	{
		new = ft_lstnew(numbers[i]);
		ft_lstadd_back(stack, new);
		i++;
	}
	set_index(stack);
}

void	init_stack(int argc, char **argv, t_list **stack)
{
	char	**numbers;

	if (argc == 2 && ft_strrchr(argv[1], ' '))
		numbers = ft_split(argv[1], ' ');
	else
	{
		argv++;
		numbers = argv;
	}
	fill_stack(numbers, stack);
}

void	empty_stack(t_list **stack)
{
	*stack = ft_lstnew(NULL);
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
			ft_printf("(%s) ", temp->content);
		else
			ft_printf("null ");
		temp = temp->next;
	}
	ft_printf("\n");
}

