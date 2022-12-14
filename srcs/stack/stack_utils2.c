/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:40:35 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 21:56:16 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty(t_stack **stack)
{
	if (!stack || !*stack)
		return (1);
	return (0);
}

int	stack_only_one_partition(t_stack *stack)
{
	int	partition;

	partition = stack->partition;
	while (stack->next)
	{
		if (stack->next->partition != partition)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_set_sorted(t_stack *stack)
{
	while (stack && stack->partition != 0)
	{
		stack->partition = 0;
		stack = stack->next;
	}
}
