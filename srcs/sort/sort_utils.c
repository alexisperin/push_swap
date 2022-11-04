/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:44:50 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 19:13:06 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	stack_size_partition(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack && !stack->begin_sorted && !stack->partition)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	empty(t_stack **stack)
{
	if (!stack || !*stack)
		return (1);
	return (0);
}
