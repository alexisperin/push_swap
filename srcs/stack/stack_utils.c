/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:44:50 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 21:56:16 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	sorted_partition(t_stack *stack)
{
	int	partition;

	partition = stack->partition;
	while (stack->next && stack->next->partition == partition)
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
	int	partition;

	size = 0;
	partition = stack->partition;
	if (!partition)
		return (0);
	while (stack && stack->partition == partition)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
