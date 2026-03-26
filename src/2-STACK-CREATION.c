/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-STACK-CREATION.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:12:51 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/04 14:21:21 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number_syntax(const char *s1)
{
	size_t	i;

	i = 0;
	if (s1[i] == '+' || s1[i] == '-')
		i++;
	if (s1[i] == '\0')
		return (0);
	while (s1[i])
	{
		if (s1[i] < '0' || s1[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_n(int argc, char **argv, t_stack *stack_a)
{
	int				i;
	long long int	num;

	i = 1;
	while (i < argc)
	{
		if (valid_number_syntax(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			return (1);
		}
		num = ft_atoi_ps(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_valid_n_from_split(char **split_args, t_stack *stack_a)
{
	int			i;
	long long	num;

	i = 0;
	while (split_args[i])
	{
		if (valid_number_syntax(split_args[i]) == 0)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			return (1);
		}
		num = ft_atoi_ps(split_args[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			return (1);
		}
		i++;
	}
	return (0);
}

int	verif_fill_up_split(char **argv, t_stack *stack_a)
{
	char	**split_args;

	split_args = ft_split(argv[1], ' ');
	if (!split_args)
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (0);
	}
	if (check_valid_n_from_split(split_args, stack_a))
	{
		free_split_args(split_args);
		return (0);
	}
	fill_up_stack_a(stack_a, split_args, 1);
	free_split_args(split_args);
	return (1);
}

void	fill_up_stack_a(t_stack *stack_a, char **argv, int split)
{
	int	i;

	i = 0;
	if (split == 0)
		i++;
	while (argv[i])
	{
		add_elmt_last(stack_a, (int)ft_atoi_ps(argv[i]));
		i++;
	}
}
