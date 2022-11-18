/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:25:41 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 14:20:55 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	push_low_high(t_stack **stack_a, t_stack **stack_b, int loc)
{
	if (loc == 1)
	{
		(*stack_a)->partition *= 3;
		(*stack_a)->partition += 1;
		pb(stack_a, stack_b);
	}
	else
	{
		(*stack_a)->partition *= 3;
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	return (1);
}

static void	partition_end(t_stack **stack_a, int part)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->partition == part)
	{
		tmp->partition = (part * 3) + 2;
		tmp = tmp->next;
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

static void	threeway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median_low;
	int	median_high;
	int	to_push;
	int	partition;

	median_low = get_median_low(*stack_a);
	median_high = get_median_high(*stack_a);
	to_push = ((size / 3) * 2) + size % 3;
	partition = (*stack_a)->partition;
	while (to_push > 0)
	{
		if ((*stack_a)->value < median_low)
			to_push -= push_low_high(stack_a, stack_b, 0);
		else if ((*stack_a)->value <= median_high)
			to_push -= push_low_high(stack_a, stack_b, 1);
		else
		{
			(*stack_a)->partition = (partition * 3) + 2;
			ra(stack_a);
		}
	}
	partition_end(stack_a, partition);
}

static void	twoway_partition(t_stack **stack_a, t_stack **stack_b, int size)
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
			to_push -= push_low_high(stack_a, stack_b, 1);
		else
		{
			(*stack_a)->partition = (partition * 3) + 2;
			ra(stack_a);
		}
	}
	partition_end(stack_a, partition);
}

void	partition_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size_partition(*stack_a);
	if (size <= 3 || sorted_partition(*stack_a))
		return ;
	else if (size <= 6)
		twoway_partition(stack_a, stack_b, size);
	else
		threeway_partition(stack_a, stack_b, size);
}
