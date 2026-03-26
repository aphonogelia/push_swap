/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-MISC-UTIL.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:42:01 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 21:03:49 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *stack)
{
	stack->head = NULL;
}

long long int	ft_atoi_ps(char *str)
{
	size_t			i;
	int				sig;
	long long int	nb;

	i = 0;
	nb = 0;
	sig = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (sig * nb);
}

void	free_split_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->head = NULL;
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
