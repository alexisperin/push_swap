/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:58:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/15 09:40:14 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_next_partition(t_stack **stack_a, t_stack **stack_b)
{
	int	partition;

	partition = (*stack_b)->partition;
	while (*stack_b && (*stack_b)->partition == partition)
		pa(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	while (!sorted(*stack_a) || !empty(stack_b))
	{
		while (stack_size_partition(*stack_a) > 3)
			twoway_partition(stack_a, stack_b, stack_size_partition(*stack_a));
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
