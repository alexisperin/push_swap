/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:32:57 by aperin            #+#    #+#             */
/*   Updated: 2022/11/15 14:02:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h> // TO REMOVE !!!

typedef struct s_stack
{
	int				value;
	int				partition;
	struct s_stack	*next;
}					t_stack;

void	print_stack(t_stack *stack); // TO REMOVE !!!

// Stack init and free
t_stack	*init_stack(int ac, char **av);
t_stack	*free_stack(t_stack *stack);

// Operations
void	ft_swap(t_stack *stack);
void	ft_push(t_stack **stack_1, t_stack **stack_2);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);

// Actions
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Sort
void	sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_first_three(t_stack **stack);

// Sort utils
int		sorted(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_size_partition(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
int		empty(t_stack **stack);
int		stack_only_one_partition(t_stack *stack);
void	stack_set_sorted(t_stack *stack_a);

// Sort three utils
int		stack_three_max(t_stack *stack);
int		stack_three_min(t_stack *stack);

// Median
int		get_median(t_stack *stack);
int		get_median_low(t_stack *stack);
int		get_median_high(t_stack *stack);

// Partition
void	twoway_partition(t_stack **stack_a, t_stack **stack_b, int size);
void	threeway_partition(t_stack **stack_a, t_stack **stack_b, int size);

// Error
int		print_error(void);

// Utils
int		ft_atoi(const char *str, int *invalid);

#endif
