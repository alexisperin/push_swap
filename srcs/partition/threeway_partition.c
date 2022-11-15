/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeway_partition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:39:25 by aperin            #+#    #+#             */
/*   Updated: 2022/11/15 09:40:59 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_low(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_a)->partition *= 3;
	(*stack_a)->partition += 2;
	pb(stack_a, stack_b);
	rb(stack_b);
	(*to_push)--;
}

static void	push_high(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_a)->partition *= 3;
	(*stack_a)->partition += 1;
	pb(stack_a, stack_b);
	(*to_push)--;
}

static void	threeway_partition2(t_stack **stack_a, int partition)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->partition == partition)
	{
		tmp->partition = partition * 3;
		tmp = tmp->next;
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
	to_push = (size / 3) * 2;
	partition = (*stack_a)->partition;
	while (to_push > 0)
	{
		if ((*stack_a)->value < median_low)
			push_low(stack_a, stack_b, &to_push);
		else if ((*stack_a)->value <= median_high)
			push_high(stack_a, stack_b, &to_push);
		else
		{
			(*stack_a)->partition = partition * 3;
			ra(stack_a);
		}
	}
	threeway_partition2(stack_a, partition);
}