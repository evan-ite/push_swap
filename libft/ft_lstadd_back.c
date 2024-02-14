/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:43:45 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/14 13:35:51 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	new->next = NULL;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
