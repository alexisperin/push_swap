/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twoway_partition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:39:10 by aperin            #+#    #+#             */
/*   Updated: 2022/11/17 14:36:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	twoway_partition2(t_stack **stack_a, int partition)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->partition == partition)
	{
		tmp->partition = (partition * 3) + 2;
		tmp = tmp->next;
	}
	tmp = stack_last(*stack_a);
	if (!sorted(*stack_a) && !stack_only_one_partition(*stack_a))
	{
		while (tmp->partition == (partition * 3) + 2)
		{
			rra(stack_a);
			tmp = stack_last(*stack_a);
		}
	}
}

void	twoway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		median;
	int		to_push;
	int		partition;

	median = get_median(*stack_a);
	to_push = size / 2;
	partition = (*stack_a)->partition;
	while (to_push > 0)
	{
		if ((*stack_a)->value < median)
		{
			(*stack_a)->partition = (partition * 3);
			pb(stack_a, stack_b);
			to_push--;
		}
		else
		{
			(*stack_a)->partition = (partition * 3) + 2;
			ra(stack_a);
		}
	}
	twoway_partition2(stack_a, partition);
}
