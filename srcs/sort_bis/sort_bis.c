/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:46:21 by aperin            #+#    #+#             */
/*   Updated: 2022/11/17 16:54:49 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	locate_partition(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_last;
	t_stack	*b_last;
	int		ret;

	ret = 0;
}

void	sort_bis(t_stack **stack_a, t_stack **stack_b)
{
	int	partition_location;

	while (!sorted(*stack_a) || !empty(stack_b))
	{
		partition_location = locate_partition(stack_a, stack_b);
		if (partition_location == 1)
			partition_a(stack_a, stack_a);
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
			stack_set_sorted(*stack_a);
		}
	}
}
