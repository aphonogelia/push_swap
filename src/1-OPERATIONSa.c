/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:49:20 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/01 17:04:28 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->prev = second;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	stack->head = second;
}

void	push_stack(t_stack *stackfrom, t_stack *stackto)
{
	t_node	*firstfrom;

	if (stackfrom->head == NULL)
		return ;
	firstfrom = stackfrom->head;
	stackfrom->head = firstfrom->next;
	if (stackfrom->head != NULL)
		stackfrom->head->prev = NULL;
	firstfrom->next = stackto->head;
	if (stackto->head != NULL)
		stackto->head->prev = firstfrom;
	stackto->head = firstfrom;
}

void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->head;
	last = stack->head;
	if (first == NULL || first->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	stack->head = first->next;
	stack->head->prev = NULL;
	first->next = NULL;
}

void	rev_rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->head;
	last = stack->head;
	if (first == NULL || first->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
}

void	sa(t_stack *stack)
{
	swap_stack(stack);
	write(1, "sa\n", 3);
}
