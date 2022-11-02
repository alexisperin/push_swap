/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:37:12 by aperin            #+#    #+#             */
/*   Updated: 2022/11/02 21:14:06 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (!stack_a || !stack_a->next)
		return ;
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (!stack_b || !stack_b->next)
		return ;
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
