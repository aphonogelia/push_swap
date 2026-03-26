/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-STACK-SORT.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:57:00 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 21:09:53 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node_to_top_a(t_node *node, t_stack *stack)
{
	int	size;

	size = stack_size(stack);
	add_index(stack);
	if (node == stack->head)
		return ;
	else if (node->index > size / 2)
	{
		while (node != stack->head)
			rra(stack);
	}
	else
	{
		while (node != stack->head)
			ra(stack);
	}
	clear_index(stack);
}

void	move_node_to_top_b(t_node *node, t_stack *stack)
{
	int	size;

	size = stack_size(stack);
	add_index(stack);
	if (node == stack->head)
		return ;
	else if (node->index > size / 2)
	{
		while (node != stack->head)
			rrb(stack);
	}
	else
	{
		while (node != stack->head)
			rb(stack);
	}
	clear_index(stack);
}

void	move_nodes_top(t_node *noda, t_node *nodb, t_stack *a, t_stack *b)
{
	int	na;
	int	nb;

	na = stack_size(a);
	nb = stack_size(b);
	add_index(a);
	add_index(b);
	if (noda == a->head || nodb == b->head)
		return ;
	else if (noda->index > na / 2 && nodb->index > nb / 2)
	{
		while (!(noda == a->head || nodb == b->head))
			rrr(a, b);
	}
	else if (noda->index <= na / 2 && nodb->index <= nb / 2)
	{
		while (!(noda == a->head || nodb == b->head))
			rr(a, b);
	}
	clear_index(a);
	clear_index(b);
}

void	clear_lis(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->lis_length = 0;
		current->is_lis = 0;
		current->subsequence = 0;
		current = current->next;
	}
}
