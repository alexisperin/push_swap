/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:46:21 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 16:31:11 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	locate_partition(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	a_end;
	int	b;
	int	b_end;

	a = (*stack_a)->partition;
	a_end = stack_last(*stack_a)->partition;
	b = -1;
	b_end = -1;
	if (!empty(stack_b))
	{
		b = (*stack_b)->partition;
		b_end = stack_last(*stack_b)->partition;
	}
	if (a >= a_end && a > b && a > b_end)
		return (1);
	else if (a_end > a && a_end > b && a_end > b_end)
		return (2);
	else if (b > a && b > a_end && b >= b_end)
		return (3);
	else
		return (4);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	partition_location;

	while (!sorted(*stack_a) || !empty(stack_b))
	{
		partition_location = locate_partition(stack_a, stack_b);
		if (partition_location == 1)
			partition_a(stack_a, stack_b);
		else if (partition_location == 2)
			partition_a_end(stack_a, stack_b);
		else if (partition_location == 3)
			partition_b(stack_a, stack_b);
		else if (partition_location == 4)
			partition_b_end(stack_a, stack_b);
		if (stack_size_partition(*stack_a) <= 3 && !sorted_partition(*stack_a))
		{
			if (stack_size(*stack_a) <= 3)
				sort_three(stack_a);
			else
				sort_first_three(stack_a);
		}
		if (sorted_partition(*stack_a))
			stack_set_sorted(*stack_a);
	}
}
