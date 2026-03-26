/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-OPERATIONSc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:10:01 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/08 16:16:03 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack)
{
	rotate_stack(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	rotate_stack(stacka);
	rotate_stack(stackb);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack)
{
	rev_rotate_stack(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	rev_rotate_stack(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stacka, t_stack *stackb)
{
	rev_rotate_stack(stacka);
	rev_rotate_stack(stackb);
	write(1, "rrr\n", 4);
}
