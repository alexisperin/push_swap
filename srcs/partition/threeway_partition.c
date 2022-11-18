/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeway_partition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:39:25 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 08:29:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_low(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_a)->partition *= 3;
	pb(stack_a, stack_b);
	(*to_push)--;
}

static void	push_high(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_a)->partition *= 3;
	(*stack_a)->partition += 1;
	pb(stack_a, stack_b);
	rb(stack_b);
	(*to_push)--;
}

static void	threeway_partition2(t_stack **stack_a, t_stack **stack_b, int part)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->partition == part)
	{
		tmp->partition = (part * 3) + 2;
		tmp = tmp->next;
	}
	tmp = stack_last(*stack_b);
	while (tmp->partition == (part * 3) + 1)
	{
		rrb(stack_b);
		tmp = stack_last(*stack_b);
	}
	tmp = stack_last(*stack_a);
	if (!sorted(*stack_a) && !stack_only_one_partition(*stack_a))
	{
		while (tmp->partition == (part * 3) + 2)
		{
			rra(stack_a);
			tmp = stack_last(*stack_a);
		}
	}
}

void	threeway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		median_low;
	int		median_high;
	int		to_push;
	int		partition;

	median_low = get_median_low(*stack_a);
	median_high = get_median_high(*stack_a);
	to_push = ((size / 3) * 2) + size % 3;
	partition = (*stack_a)->partition;
	while (to_push > 0)
	{
		if ((*stack_a)->value < median_low)
			push_low(stack_a, stack_b, &to_push);
		else if ((*stack_a)->value <= median_high)
			push_high(stack_a, stack_b, &to_push);
		else
		{
			(*stack_a)->partition = (partition * 3) + 2;
			ra(stack_a);
		}
	}
	threeway_partition2(stack_a, stack_b, partition);
}
