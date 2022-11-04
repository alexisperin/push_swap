/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:44:50 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 12:02:28 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack->next)
	{
		if (max < stack->next->value)
			max = stack->next->value;
		stack = stack->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack->next)
	{
		if (min > stack->next->value)
			min = stack->next->value;
		stack = stack->next;
	}
	return (min);
}
