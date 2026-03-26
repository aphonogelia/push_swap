/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-STACK-SORT2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:57:23 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 21:05:38 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_biggest(t_stack *stack)
{
	t_node	*biggest;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head->next;
	biggest = stack->head;
	while (current)
	{
		if (current->rank > biggest->rank)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_node	*find_biggest_subseq(t_stack *stack)
{
	t_node	*biggest;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head->next;
	biggest = stack->head;
	while (current)
	{
		if (current->lis_length > biggest->lis_length)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_node	*find_second_biggest(t_stack *stack, t_node *the_node)
{
	t_node	*target;
	t_node	*current;

	target = NULL;
	current = stack->head;
	if (the_node == NULL || stack->head == NULL)
		return (NULL);
	while (current)
	{
		if (current->rank > the_node->rank)
		{
			if (target == NULL || current->rank < target->rank)
				target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		return (find_smallest(stack));
	return (target);
}

void	sort_stack_value(t_stack *stack)
{
	t_node	*tempi;
	t_node	*tempj;
	int		temp;

	if (stack->head == NULL)
		return ;
	tempi = stack->head;
	while (tempi)
	{
		tempj = tempi->next;
		while (tempj)
		{
			if (tempj->value < tempi->value)
			{
				temp = tempi->value;
				tempi->value = tempj->value;
				tempj->value = temp;
				temp = tempi->index;
				tempi->index = tempj->index;
				tempj->index = temp;
			}
			tempj = tempj->next;
		}
		tempi = tempi->next;
	}
}

void	sort_stack_index(t_stack *stack)
{
	t_node	*tempi;
	t_node	*tempj;
	int		temp;

	if (stack->head == NULL)
		return ;
	tempi = stack->head;
	while (tempi)
	{
		tempj = tempi->next;
		while (tempj)
		{
			if (tempj->index < tempi->index)
			{
				temp = tempi->index;
				tempi->index = tempj->index;
				tempj->index = temp;
				temp = tempi->rank;
				tempi->rank = tempj->rank;
				tempj->rank = temp;
			}
			tempj = tempj->next;
		}
		tempi = tempi->next;
	}
}
