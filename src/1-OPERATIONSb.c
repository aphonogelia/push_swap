/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:08:51 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/01 17:05:27 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	swap_stack(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	swap_stack(stacka);
	swap_stack(stackb);
	write(1, "ss\n", 3);
}

void	pa(t_stack *stackfrom, t_stack *stackto)
{
	push_stack(stackfrom, stackto);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stackfrom, t_stack *stackto)
{
	push_stack(stackfrom, stackto);
	write(1, "pb\n", 3);
}

void	ra(t_stack *stack)
{
	rotate_stack(stack);
	write(1, "ra\n", 3);
}
