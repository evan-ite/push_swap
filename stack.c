/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:19:01 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/09 16:24:19 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**fill_stack(char **numbers, t_list **head)
{
	t_list	*node;
	int		len;
	int		i;

	len = 0;
	while (numbers[len])
		len++;
	head = (t_list **)malloc(len * sizeof(t_list *));
	if (!head)
		return (NULL);
	*head = NULL;
	i = 0;
	node = ft_lstnew(numbers[i]);
	node->index = 0;
	if (!node)
	{
		free(head);
		return (NULL);
	}
	*head = node;
	while (numbers[++i])
		ft_lstadd_back(head, ft_lstnew(numbers[i]));
	set_index(head);
	return (head);
}

t_list	**init_stack(int argc, char **argv)
{
	t_list	**head;
	char	**numbers;

	if (argc == 2 && ft_strrchr(argv[1], ' '))
		numbers = ft_split(argv[1], ' ');
	else
	{
		argv++;
		numbers = argv;
	}
	head = NULL;
	head = fill_stack(numbers, head);
	return (head);
}

t_list	**empty_stack()
{
	t_list	**head;

	head = (t_list **)malloc(sizeof(t_list));
	*head = ft_lstnew(NULL);
	set_index(head);
	return (head);
}

void	print_stack(t_list **head)
{
	int		i;

	i = 0;
	ft_printf("\n");
	while (head[i])
	{
		ft_printf("(%s) ", head[i]->content);
		i++;
	}
}

