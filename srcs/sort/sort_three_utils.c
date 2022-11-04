/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:14:38 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 17:43:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_three_max(t_stack *stack)
{
	int	max;
	int	count;

	max = stack->value;
	count = 1;
	while (stack->next && count < 3)
	{
		if (max < stack->next->value)
			max = stack->next->value;
		stack = stack->next;
		count++;
	}
	return (max);
}

int	stack_three_min(t_stack *stack)
{
	int	min;
	int	count;

	min = stack->value;
	count = 1;
	while (stack->next && count < 3)
	{
		if (min > stack->next->value)
			min = stack->next->value;
		stack = stack->next;
		count++;
	}
	return (min);
}
