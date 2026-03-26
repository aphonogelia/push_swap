/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:58:45 by htharrau          #+#    #+#             */
/*   Updated: 2024/08/09 15:03:06 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <stddef.h>
# include <math.h>

typedef struct s_node {
	int				rank;
	int				value;
	int				index;
	int				lis_length;
	int				subsequence;
	int				is_lis;
	int				nb_move;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	struct s_node	*head;
}	t_stack;

// 0-MISC UTIL
void			init(t_stack *stack);
long long int	ft_atoi_ps(char *str);
void			free_split_args(char **split_args);
void			free_stack(t_stack *stack);
void			free_stacks(t_stack *stack_a, t_stack *stack_b);

// 0-FT_SPLIT
char			**ft_split(char const *s, char c);

//1-OPERATIONS
void			swap_stack(t_stack *stack);
void			push_stack(t_stack *stackfrom, t_stack *stackto);
void			rotate_stack(t_stack *stack);
void			rev_rotate_stack(t_stack *stack);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stacka, t_stack *stackb);
void			pa(t_stack *stackfrom, t_stack *stackto);
void			pb(t_stack *stackfrom, t_stack *stackto);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stacka, t_stack *stackb);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stacka, t_stack *stackb);

// 2-STACK CREATION
int				valid_number_syntax(const char *s1);
int				check_valid_n(int argc, char **argv, t_stack *a);
int				check_valid_n_from_split(char **s_args, t_stack *a);
int				verif_fill_up_split(char **argv, t_stack *a);
void			fill_up_stack_a(t_stack *stack_a, char **argv, int split);

// 2-BEFORE ALGO
int				sorted_but_rotated(t_stack *stack_a);
int				check_duplicates(t_stack *stack);
int				check_sorted(t_stack *stack);

// 3-STACK MISC
t_node			*add_elmt_last(t_stack *stack, int result);
int				stack_size(t_stack *stack);
t_node			*find_smallest(t_stack *stack);
t_node			*find_smallest_notlis(t_stack *stack);
t_node			*find_smallest_smart(t_stack *stack);

// 3-STACK RANK INDEX VALUE
void			add_rank(t_stack *stack);
void			add_index(t_stack *stack);
void			add_double_index(t_stack *stack);
void			clear_value(t_stack *stack);
void			clear_index(t_stack *stack);
// void			print_stack(t_stack *stack);
// void			print_stack_lis(t_stack *stack);

// 3-STACK SORT
void			clear_lis(t_stack *stack);
void			move_node_to_top_a(t_node *node, t_stack *stack);
void			move_node_to_top_b(t_node *node, t_stack *stack);
void			move_nodes_top(t_node *da, t_node *db, t_stack *a, t_stack *b);
t_node			*find_biggest(t_stack *stack);
t_node			*find_second_biggest(t_stack *stack, t_node *the_node);
t_node			*find_biggest_subseq(t_stack *stack);
void			sort_stack_value(t_stack *stack);
void			sort_stack_index(t_stack *stack);

// 4-MAIN SORT
void			push_swap(t_stack *stack_a, t_stack *stack_b);
void			sort_stack(t_stack *stack_a, t_stack *stack_b);
void			sort_stack_3(t_stack *stack);
void			sort_mini_stack(t_stack *stack_a, t_stack *stack_b);
void			sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void			sort_big_stack(t_stack *a, t_stack *b, int chunk_size);

// 5-UTIL ALGO
void			push_the_chunks(t_stack *a, t_stack *b, int chunk);
t_node			*find_node_to_push(t_stack *stack_a, int chunk_size);
t_node			*find_node_not_lis(t_stack *stack_a);
void			smart_merge(t_stack *stack_a, t_stack *stack_b);
t_node			*smart_find(t_stack *stack_a, t_stack *stack_b);

// 5-LONGEST INCREASING SEQUENCE
void			calcul_lis(t_stack *stack_a);
void			is_lis(t_stack *stack_a);
t_node			*find_previous_node_lis(t_stack *stack_a, int index);
int				lis_array(t_stack *stack_a);
void			mark_the_lis(t_stack *stack_a);

#endif