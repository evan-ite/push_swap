/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:18:35 by evan-ite          #+#    #+#             */
/*   Updated: 2024/02/23 12:02:28 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	if (i == 1)
		return ;
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	if (numbers)
		free(numbers);
	numbers = NULL;
}

static int	check_digits(int argc, char **argv)
{
	int		i;
	int		j;
	int		found_digit;

	i = 1;
	found_digit = 0;
	while (argv[i] && i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]) \
				&& argv[i][j] != '-')
				return (0);
			if (argv[i][j] == '-' && \
				(!ft_isdigit(argv[i][j + 1]) || argv[i][j + 1] == '\0'))
				return (0);
			if (ft_isdigit(argv[i][j++]))
				found_digit = 1;
		}
		i++;
	}
	if (!found_digit)
		return (0);
	return (1);
}

static int	check_dups_overflow(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		if (ft_atoi(numbers[i]) > INT_MAX || ft_atoi(numbers[i]) < INT_MIN)
			return (0);
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**check_args(int argc, char **argv)
{
	char	**numbers;
	int		i;

	i = 0;
	if (!check_digits(argc, argv))
		return (NULL);
	if (argc == 2 && ft_strrchr(argv[1], ' '))
		numbers = ft_split(argv[1], ' ');
	else
	{
		while (argv[++i])
		{
			if (ft_strrchr(argv[i], ' '))
				return (NULL);
		}
		argv++;
		numbers = argv;
	}
	if (!check_dups_overflow(numbers))
	{
		if (i == 0)
			free_numbers(numbers);
		return (NULL);
	}
	return (numbers);
}

int	check_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)(temp->next)->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
