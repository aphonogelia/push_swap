/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-STACK-RANK-INDEX-VALUE.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:04:40 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 21:09:48 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rank(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (stack->head == NULL)
		return ;
	current = stack->head;
	i = 1;
	while (current)
	{
		current->rank = i++;
		current = current->next;
	}
}

void	add_index(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (stack->head == NULL)
		return ;
	current = stack->head;
	i = 1;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}

void	add_double_index(t_stack *stack)
{
	int		i;
	t_node	*current;
	int		n;

	if (stack->head == NULL)
		return ;
	n = stack_size(stack);
	current = stack->head;
	i = 1;
	while (current)
	{
		if (i <= n / 2)
			current->index = i;
		else
			current->index = n - i + 1;
		current = current->next;
		i++;
	}
}

void	clear_value(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->value = 0;
		current = current->next;
	}
}

void	clear_index(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
}

// TO DELETE //
/* void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	printf("Value\tIndex\tRank\n");
	while (current != NULL)
	{
		printf("%d\t%d\t%d\n", current->value, current->index, current->rank);
		current = current->next;
	}
	printf("\n");
} */

// TO DELETE //
/* void	print_stack_lis(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	printf("Value\tIndex\tRank\tlis_len\tsubs\tIS_lis\n");
	while (current != NULL)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", current->value, current->index, 
			current->rank, current->lis_length, current->subsequence, current->is_lis);
		current = current->next;
	}
	printf("\n");
} */
