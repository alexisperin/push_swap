/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:29:02 by aperin            #+#    #+#             */
/*   Updated: 2022/11/03 10:49:51 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp->next->next = 0;
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp->next->next = 0;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
