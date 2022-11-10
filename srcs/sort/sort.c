/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:58:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 18:13:30 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	twoway_partition2(t_stack **stack_a, int partition)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->partition == partition)
	{
		tmp->partition = partition * 2;
		tmp = tmp->next;
	}
	tmp = stack_last(*stack_a);
	if (!sorted(*stack_a) && !stack_only_one_partition(*stack_a))
	{
		while (tmp->partition)
		{
			rra(stack_a);
			tmp = stack_last(*stack_a);
		}
	}
}

static void	twoway_partition(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		size;
	int		to_push;
	int		partition;

	median = get_median(*stack_a);
	size = stack_size_partition(*stack_a);
	to_push = size / 2;
	partition = (*stack_a)->partition;
	while (to_push > 0)
	{
		if ((*stack_a)->value < median)
		{
			(*stack_a)->partition = (partition * 2) + 1;
			pb(stack_a, stack_b);
			to_push--;
		}
		else
		{
			(*stack_a)->partition = partition * 2;
			ra(stack_a);
		}
	}
	twoway_partition2(stack_a, partition);
}

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
			twoway_partition(stack_a, stack_b);
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
