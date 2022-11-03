/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:52:10 by aperin            #+#    #+#             */
/*   Updated: 2022/11/03 11:08:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = 0;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = 0;
	last->next = *stack_b;
	*stack_b = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
