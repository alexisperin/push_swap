/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_twoway_partition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:04:43 by aperin            #+#    #+#             */
/*   Updated: 2022/11/16 11:11:27 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_twoway_partition2(t_stack **stack_b, int partition)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp && tmp->partition == partition)
	{
		tmp->partition = (partition * 3);
		tmp = tmp->next;
	}
	tmp = stack_last(*stack_b);
	if (!stack_only_one_partition(*stack_b))
	{
		while (tmp->partition == (partition * 3))
		{
			rrb(stack_b);
			tmp = stack_last(*stack_b);
		}
	}
}

void	push_twoway_partition(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		median;
	int		to_push;
	int		partition;

	size = stack_size_partition(*stack_b);
	median = get_median(*stack_b);
	to_push = size / 2 + size % 2;
	partition = (*stack_b)->partition;
	while (to_push > 0)
	{
		if ((*stack_b)->value >= median)
		{
			(*stack_b)->partition = (partition * 3) + 1;
			pa(stack_a, stack_b);
			to_push--;
		}
		else
		{
			(*stack_b)->partition = partition * 3;
			rb(stack_b);
		}
	}
	push_twoway_partition2(stack_b, partition);
}
