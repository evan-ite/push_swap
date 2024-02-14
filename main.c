/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:53 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/14 14:56:14 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (write(2, "./push_swap 'list of numbers'\n", 7));
	else
	{
		stack_a = NULL;
		stack_b = NULL;
		init_stack(argc, argv, &stack_a);
		empty_stack(&stack_b);
		// insertion_sort(stack_a, stack_b);
		print_stack(&stack_a);
		print_stack(&stack_b);
		ft_lstclear(&stack_a, NULL);
		return (1);
	}
}
