/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:45:53 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/23 12:02:31 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	run(char **numbers)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack(numbers, &stack_a);
	if (check_sorted(&stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (1);
	}
	if (ft_lstsize(stack_a) <= 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_all(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**numbers;

	if (argc < 2)
		return (write(2, "./push_swap [list of numbers]\n", 31));
	numbers = check_args(argc, argv);
	if (!numbers)
		return (write(2, "Error\n", 7));
	else
	{
		run(numbers);
		if (argc == 2)
			free_numbers(numbers);
		return (1);
	}
}
