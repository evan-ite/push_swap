/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:53 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/15 17:27:27 by elisevanite      ###   ########.fr       */
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
		if (ft_lstsize(stack_a) <= 3)
			sort_three(&stack_a);
		else if (ft_lstsize(stack_a) <= 5)
			sort_five(&stack_a, &stack_b);
		else
			sort_all(&stack_a, &stack_b);
		print_stack(&stack_a);
		print_stack(&stack_b);
		ft_lstclear(&stack_a, free);
		return (1);
	}
}
