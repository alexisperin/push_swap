/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:40:35 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 17:16:54 by aperin           ###   ########.fr       */
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

void	stack_set_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->partition != 0)
	{
		stack_a->partition = 0;
		stack_a = stack_a->next;
	}
}