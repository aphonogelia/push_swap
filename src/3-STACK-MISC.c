/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-STACK-MISC.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:55:53 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 21:05:08 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		i;
	t_node	*current;

	current = stack->head;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_node	*add_elmt_last(t_stack *stack, int result)
{
	t_node	*temp;
	t_node	*last;

	temp = malloc(sizeof(t_node));
	if (!temp)
		return (NULL);
	temp->prev = NULL;
	temp->value = result;
	temp->lis_length = 1;
	temp->subsequence = 0;
	temp->nb_move = 0;
	temp->is_lis = 0;
	temp->next = NULL;
	if (stack->head == NULL)
		stack->head = temp;
	else 
	{
		last = stack->head;
		while (last->next != NULL)
			last = last->next;
		temp->prev = last;
		last->next = temp;
	}
	return (temp);
}

t_node	*find_smallest(t_stack *stack)
{
	t_node	*smallest;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head->next;
	smallest = stack->head;
	while (current)
	{
		if (current->rank < smallest->rank)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_node	*find_smallest_smart(t_stack *stack)
{
	t_node	*smallest;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head->next;
	smallest = stack->head;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_node	*find_smallest_notlis(t_stack *stack)
{
	t_node	*smallest;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current = stack->head;
	while (current && current->is_lis == 1)
		current = current->next;
	if (!current)
		return (NULL);
	if (current)
	{
		smallest = current;
		current = current->next;
	}
	while (current)
	{
		if (current->rank < smallest->rank && current->is_lis == 0)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}
