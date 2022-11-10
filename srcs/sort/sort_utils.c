/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:44:50 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 11:58:18 by aperin           ###   ########.fr       */
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

int	empty(t_stack **stack)
{
	if (!stack || !*stack)
		return (1);
	return (0);
}
