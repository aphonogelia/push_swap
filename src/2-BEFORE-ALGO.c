/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-BEFORE-ALGO.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:56:00 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/08 16:40:22 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IF SORTED BUT ROTATED - WE ROTATE (OR REVERSE ROTATE) - 1 YES - 0 NO

int	check_duplicates(t_stack *stack)
{
	t_node	*current;

	if (stack->head == NULL)
		return (0);
	current = stack->head;
	while (current->next)
	{
		if (current->value == current->next->value)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->value >= current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	sorted_but_rotated(t_stack *stack_a)
{
	t_node	*min;
	int		i;
	int		sorted;

	min = find_smallest(stack_a);
	i = 0;
	sorted = 0;
	while (min != stack_a->head)
	{
		rotate_stack(stack_a);
		i++;
	}
	if (check_sorted(stack_a) == 1)
		sorted = 1;
	while (i > 0)
	{
		rev_rotate_stack(stack_a);
		i--;
	}
	if (sorted == 1)
	{
		move_node_to_top_a(min, stack_a);
		return (1);
	}
	return (0);
}
