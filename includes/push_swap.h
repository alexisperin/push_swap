/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:32:57 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 14:05:14 by aperin           ###   ########.fr       */
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
	struct s_stack	*next;
}					t_stack;

// Stack init and free
t_stack	*init_stack(int ac, char **av);
t_stack	*free_stack(t_stack *stack);

// Stack utils
int		is_sorted(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);

int		median(t_stack *stack);

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

// Sorting
void	sort_3(t_stack **stack);

// Error
int		print_error(void);

// Utils
int		ft_atoi(const char *str, int *invalid);

#endif
