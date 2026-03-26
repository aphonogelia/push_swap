/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-MAIN.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:48:16 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/09 20:46:41 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• You have to turn in a Makefile. It must not relink.
• Global variables are forbidden.
• You have to write a program named push_swap that takes as an arg the stack a 
formatted as a list of integers. The first arg should be at the top of the stack
• The program must display the smallest list of instructions possible to sort 
the stack a, the smallest number being at the top.
• Instructions must be separated by a ’\n’ and nothing else.
• The goal is to sort the stack with the lowest possible number of operations. 
• If no parameters are specified, the program must not display anything and give
the prompt back.
• In case of error, it must display "Error" followed by a ’\n’ on the STDERR.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.
*/

// REMOVE PRINT_STACK FUNCTION

//	printf("value\tindex\trank\n");
//	print_stack(&stack_a);

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			stack_a;
	t_stack			stack_b;

	if (argc == 1)
		return (1);
	init(&stack_a);
	init(&stack_b);
	if (argc == 2)
	{
		if (verif_fill_up_split(argv, &stack_a) == 0)
			return (1);
	}
	else if (argc > 2)
	{
		if (check_valid_n(argc, argv, &stack_a) == 1)
			return (1);
		fill_up_stack_a(&stack_a, argv, 0);
	}
	add_index(&stack_a);
	push_swap(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sorted(stack_a) == 1)
		return ;
	sort_stack_value(stack_a);
	if (check_duplicates(stack_a) == 1)
		return ;
	add_rank(stack_a);
	sort_stack_index(stack_a);
	clear_value(stack_a);
	if (sorted_but_rotated(stack_a) == 0)
	{
		mark_the_lis(stack_a);
		add_double_index(stack_a);
		sort_stack(stack_a, stack_b);
	}
}
