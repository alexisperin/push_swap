/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:58:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/16 15:35:40 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_next_partition(t_stack **stack_a, t_stack **stack_b)
{
	int	partition;

	if (stack_size_partition(*stack_b) <= 3)
	{
		partition = (*stack_b)->partition;
		while (*stack_b && (*stack_b)->partition == partition)
			pa(stack_a, stack_b);
	}
	else if (stack_size_partition(*stack_b) <= 6)
		push_twoway_partition(stack_a, stack_b);
	else
		push_threeway_partition(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	partition_size;

	while (!sorted(*stack_a) || !empty(stack_b))
	{
		partition_size = stack_size_partition(*stack_a);
		while (partition_size > 6)
		{
			threeway_partition(stack_a, stack_b, partition_size);
			partition_size = stack_size_partition(*stack_a);
		}
		if (partition_size > 3)
			twoway_partition(stack_a, stack_b, partition_size);
		if (!sorted(*stack_a) && stack_size_partition(*stack_a) > 1)
		{
			if (stack_size(*stack_a) <= 3)
				sort_three(stack_a);
			else
				sort_first_three(stack_a);
		}
		stack_set_sorted(*stack_a);
		if (!empty(stack_b))
			push_next_partition(stack_a, stack_b);
	}
}
