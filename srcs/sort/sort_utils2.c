/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:40:35 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 18:05:08 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
