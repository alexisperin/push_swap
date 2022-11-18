/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:46 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 16:32:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

	tmp = stack_last(*stack_b);
	while (tmp->partition == part)
	{
		tmp->partition *= 3;
		rrb(stack_b);
		tmp = stack_last(*stack_b);
	}
}

static void	threeway_partition(t_stack **stack_a, t_stack **stack_b,
								t_stack *tmp, int size)
{
	int	median_low;
	int	median_high;
	int	to_push;
	int	partition;

	median_low = get_median_low(tmp);
	median_high = get_median_high(tmp);
	to_push = ((size / 3) * 2) + size % 3;
	partition = stack_last(*stack_b)->partition;
	while (to_push > 0)
	{
		rrb(stack_b);
		if ((*stack_b)->value < median_low)
			(*stack_b)->partition *= 3;
		else if ((*stack_b)->value <= median_high)
			to_push -= push_low_high(stack_a, stack_b, 0);
		else
			to_push -= push_low_high(stack_a, stack_b, 1);
	}
	partition_end(stack_b, partition);
}

static void	twoway_partition(t_stack **stack_a, t_stack **stack_b,
								t_stack *tmp, int size)
{
	int		median;
	int		to_push;
	int		partition;

	median = get_median(tmp);
	to_push = (size / 2) + (size % 2);
	partition = stack_last(*stack_b)->partition;
	while (to_push > 0)
	{
		rrb(stack_b);
		if ((*stack_b)->value < median)
			(*stack_b)->partition = partition * 3;
		else
			to_push -= push_low_high(stack_a, stack_b, 1);
	}
	partition_end(stack_b, partition);
}

void	partition_b_end(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		size;
	int		partition;

	partition = stack_last(*stack_b)->partition;
	tmp = *stack_b;
	while (tmp->partition != partition)
		tmp = tmp->next;
	size = stack_size_partition(tmp);
	if (size <= 3)
	{
		while (!empty(stack_b) && stack_last(*stack_b)->partition == partition)
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
	}
	else if (size <= 6)
		twoway_partition(stack_a, stack_b, tmp, size);
	else
		threeway_partition(stack_a, stack_b, tmp, size);
}
