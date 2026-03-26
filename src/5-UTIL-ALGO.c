/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-UTIL-ALGO.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:28:54 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/16 20:49:50 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_node_not_lis(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->head)
		return (NULL);
	first = stack_a->head;
	last = stack_a->head;
	while (last->next)
		last = last->next;
	while (first != last && first->prev != last) 
	{
		if (first->is_lis == 0)
			return (first);
		if (last->is_lis == 0)
			return (last);
		first = first->next;
		last = last->prev;
	}
	if (first->is_lis == 0)
		return (first);
	return (NULL);
}

void	push_the_chunks(t_stack *stack_a, t_stack *stack_b, int chunk)
{
	t_node	*the_node;

	the_node = find_node_to_push(stack_a, chunk);
	while (the_node)
	{
		move_node_to_top_a(the_node, stack_a);
		pb(stack_a, stack_b);
		the_node = find_node_to_push(stack_a, chunk);
	}
}

/* void	push_the_chunks(t_stack *stack_a, t_stack *stack_b, int n, int i,
 int chunk_size)
{
	t_node	*the_node;
	int		sizea;
	int chunk = n * i++ / chunk_size;
	int j;

	j = 0;
	sizea = stack_size(stack_a);
	the_node = find_node_to_push(stack_a, chunk);
	while (the_node && stack_size(stack_a) > 3)
	{
		move_node_to_top_a(the_node, stack_a);
		pb(stack_a, stack_b);
		if (i > 1 && (j%2 == 0))
			rb(stack_b);
	//	printf("chunk is %d, n is %d, i is %d\n", chunk, sizea, i);
		j++;
		the_node = find_node_to_push(stack_a, chunk);
	}
} */

t_node	*find_node_to_push(t_stack *stack_a, int chunk)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->head)
		return (NULL);
	first = stack_a->head;
	last = stack_a->head;
	while (last->next)
		last = last->next;
	while (first != last && first->prev != last) 
	{
		if (first->rank <= chunk)
			return (first);
		if (last->rank <= chunk)
			return (last);
		first = first->next;
		last = last->prev;
	}
	if (first->rank <= chunk)
		return (first);
	return (NULL);
}

void	smart_merge(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smarta;
	t_node	*smartb;

	while (stack_size(stack_b) > 0)
	{
		smartb = smart_find(stack_a, stack_b);
		smarta = find_second_biggest(stack_a, smartb);
		move_nodes_top(smarta, smartb, stack_a, stack_b);
		move_node_to_top_b(smartb, stack_b);
		move_node_to_top_a(smarta, stack_a);
		pa(stack_b, stack_a);
	}
}

t_node	*smart_find(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*noda;
	t_node	*smart_node;

	current = stack_b->head;
	if (stack_b->head == NULL || stack_a->head == NULL)
		return (NULL);
	add_double_index(stack_a);
	add_double_index(stack_b);
	clear_value(stack_a);
	clear_value(stack_b);
	while (current)
	{
		noda = find_second_biggest(stack_a, current);
		current->value = noda->index + current->index;
		current = current->next;
	}
	smart_node = find_smallest_smart(stack_b);
	clear_index(stack_a);
	clear_index(stack_b);
	return (smart_node);
}
