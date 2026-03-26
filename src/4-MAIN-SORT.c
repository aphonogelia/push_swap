/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-MAIN-SORT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:22:10 by htharrau          #+#    #+#             */
/*   Updated: 2025/03/18 17:55:51 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_size(stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_stack_3(stack_a);
	else if (size <= 20)
		sort_mini_stack(stack_a, stack_b);
	else if (size <= 300)
		sort_small_stack(stack_a, stack_b);
	else if (size <= 350)
		sort_big_stack(stack_a, stack_b, 2);
	else 
		sort_big_stack(stack_a, stack_b, 5);
}

void	sort_stack_3(t_stack *stack)
{
	t_node	*first ;
	t_node	*second;
	t_node	*third;

	first = stack->head;
	second = first->next;
	third = second->next;
	if (first->rank > second->rank && second->rank > third->rank)
	{
		sa(stack);
		rra(stack);
	}
	else if (first->rank > third->rank && third->rank > second->rank)
		ra(stack);
	else if (second->rank > first->rank && first->rank > third->rank)
		rra(stack);
	else if (third->rank > first->rank && first->rank > second->rank)
		sa(stack);
	else if (second->rank > third->rank && third->rank > first->rank)
	{
		sa(stack);
		ra(stack);
	}
}

// PUSH FROM MIN TO MAX TO B
void	sort_mini_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_size(stack_a) > 3)
	{
		move_node_to_top_a(find_smallest(stack_a), stack_a);
		pb(stack_a, stack_b);
	}
	sort_stack_3(stack_a);
	while (stack_size(stack_b) > 0)
	{
		move_node_to_top_a(find_biggest(stack_b), stack_b);
		pa(stack_b, stack_a);
	}
}

// LIS METHOD and SMART MERGE
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*not_lis;

	not_lis = find_node_not_lis(stack_a);
	while (not_lis)
	{
		move_node_to_top_a(not_lis, stack_a);
		pb(stack_a, stack_b);
		not_lis = find_node_not_lis(stack_a);
	}
	smart_merge(stack_a, stack_b);
	move_node_to_top_a(find_smallest(stack_a), stack_a);
}

// CHUNKS and SMART MERGE
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int		i;
	int		n;

	n = stack_size(stack_a);
	i = 1;
	while (i < chunk_size)
		push_the_chunks(stack_a, stack_b, n * i++ / chunk_size);
	while (stack_size(stack_a) > 3)
		pb(stack_a, stack_b);
	sort_stack_3(stack_a);
	smart_merge(stack_a, stack_b);
	move_node_to_top_a(find_smallest(stack_a), stack_a);
}
