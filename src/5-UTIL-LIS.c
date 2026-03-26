/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-UTIL-LIS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:29:12 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 21:02:27 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_lis(t_stack *stack_a)
{
	t_node	*i;
	t_node	*j;

	i = stack_a->head->next;
	j = stack_a->head;
	while (i) 
	{
		j = stack_a->head;
		while (j != i) 
		{
			if (j->rank < i->rank && j->lis_length + 1 > i->lis_length) 
			{
				i->lis_length = j->lis_length + 1;
				i->subsequence = j->index;
			}
			j = j->next;
		}
		i = i->next;
	}
}

t_node	*find_previous_node_lis(t_stack *stack_a, int index)
{
	t_node	*current;

	current = stack_a->head;
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	is_lis(t_stack *stack_a)
{
	t_node	*previous;
	t_node	*last;
	int		index;

	last = find_biggest_subseq(stack_a);
	last->is_lis = 1;
	index = last->subsequence;
	while (index > -1)
	{
		previous = find_previous_node_lis(stack_a, index);
		if (previous == NULL)
			break ;
		previous->is_lis = 1;
		index = previous->subsequence;
	}
}

int	lis_array(t_stack *stack_a)
{
	int		n;
	int		i;
	t_node	*temp;
	int		*lis;
	int		index_max;

	i = 0;
	n = stack_size(stack_a);
	lis = (int *)malloc(sizeof(int) * n);
	index_max = 0;
	while (i < n) 
	{
		calcul_lis(stack_a);
		temp = find_biggest_subseq(stack_a);
		lis[i] = temp->lis_length;
		if (i > 0 && lis[i] > lis[i - 1])
			index_max = i;
		clear_lis(stack_a);
		rotate_stack(stack_a);
		i++;
	}
	free(lis);
	return (index_max);
}

void	mark_the_lis(t_stack *stack_a)
{
	int		index_max;
	int		i;

	index_max = lis_array(stack_a);
	i = 0;
	while (i < index_max)
	{
		rotate_stack(stack_a);
		i++;
	}
	calcul_lis(stack_a);
	is_lis(stack_a);
	while (i > 0)
	{
		rev_rotate_stack(stack_a);
		i--;
	}
}
