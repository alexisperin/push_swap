/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:49:44 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 21:56:16 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_low_high(t_stack **stack_a, t_stack **stack_b, int loc)
{
	if (loc == 1)
	{
		(*stack_b)->partition *= 3;
		(*stack_b)->partition += 2;
		pa(stack_a, stack_b);
	}
	else
	{
		(*stack_b)->partition *= 3;
		(*stack_b)->partition += 1;
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	return (1);
}

static void	partition_end(t_stack **stack_b, int part)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp && tmp->partition == part)
	{
		tmp->partition = part * 3;
		tmp = tmp->next;
	}
	tmp = stack_last(*stack_b);
	if (!stack_only_one_partition(*stack_b))
	{
		while (tmp->partition == part * 3)
		{
			rrb(stack_b);
			tmp = stack_last(*stack_b);
		}
	}
}

static void	threeway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median_low;
	int	median_high;
	int	to_push;
	int	partition;

	median_low = get_median_low(*stack_b);
	median_high = get_median_high(*stack_b);
	to_push = ((size / 3) * 2) + size % 3;
	partition = (*stack_b)->partition;
	while (to_push > 0)
	{
		if ((*stack_b)->value < median_low)
		{
			(*stack_b)->partition = partition * 3;
			rb(stack_b);
		}
		else if ((*stack_b)->value <= median_high)
			to_push -= push_low_high(stack_a, stack_b, 0);
		else
			to_push -= push_low_high(stack_a, stack_b, 1);
	}
	partition_end(stack_b, partition);
}

static void	twoway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		median;
	int		to_push;
	int		partition;

	median = get_median(*stack_b);
	to_push = (size / 2) + (size % 2);
	partition = (*stack_b)->partition;
	while (to_push > 0)
	{
		if ((*stack_b)->value >= median)
			to_push -= push_low_high(stack_a, stack_b, 1);
		else
		{
			(*stack_b)->partition = partition * 3;
			rb(stack_b);
		}
	}
	partition_end(stack_b, partition);
}

void	partition_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	partition;

	size = stack_size_partition(*stack_b);
	partition = (*stack_b)->partition;
	if (size <= 3)
	{
		while (!empty(stack_b) && (*stack_b)->partition == partition)
			pa(stack_a, stack_b);
	}
	else if (size <= 6)
		twoway_partition(stack_a, stack_b, size);
	else
		threeway_partition(stack_a, stack_b, size);
}
