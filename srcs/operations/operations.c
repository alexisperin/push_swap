/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:10:43 by aperin            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:49 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!stack_1 || !*stack_1)
		return ;
	tmp = *stack_1;
	*stack_1 = (*stack_1)->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp->next->next = 0;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = 0;
	last->next = *stack;
	*stack = last;
}
