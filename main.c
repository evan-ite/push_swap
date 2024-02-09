/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:53 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/09 16:24:31 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (write(2, "./push_swap 'list of numbers'\n", 7));
	else
	{
		stack_a = init_stack(argc, argv);
		stack_b = empty_stack();
		insertion_sort(stack_a, stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
		ft_lstclear(stack_a, NULL);
		free(stack_a);
		return (1);
	}
}
