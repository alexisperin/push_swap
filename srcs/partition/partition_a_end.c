/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:44:49 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 14:58:32 by aperin           ###   ########.fr       */
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

	tmp = stack_last(*stack_a);
	while (tmp->partition == part)
	{
		tmp->partition = (part * 3) + 2;
		rra(stack_a);
		tmp = stack_last(*stack_a);
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
	partition = stack_last(*stack_a)->partition;
	while (to_push > 0)
	{
		rra(stack_a);
		if ((*stack_a)->value < median_low)
			to_push -= push_low_high(stack_a, stack_b, 0);
		else if ((*stack_a)->value <= median_high)
			to_push -= push_low_high(stack_a, stack_b, 1);
		else
			(*stack_a)->partition = (partition * 3) + 2;
	}
	partition_end(stack_a, partition);
}

static void	twoway_partition(t_stack **stack_a, t_stack **stack_b,
								t_stack *tmp, int size)
{
	int		median;
	int		to_push;
	int		partition;

	median = get_median(tmp);
	to_push = size / 2;
	partition = stack_last(*stack_a)->partition;
	while (to_push > 0)
	{
		rra(stack_a);
		if ((*stack_a)->value < median)
			to_push -= push_low_high(stack_a, stack_b, 1);
		else
			(*stack_a)->partition = (partition * 3) + 2;
	}
	partition_end(stack_a, partition);
}

void	partition_a_end(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		size;
	int		partition;

	partition = stack_last(*stack_a)->partition;
	tmp = *stack_a;
	while (tmp->partition != partition)
		tmp = tmp->next;
	size = stack_size_partition(tmp);
	if (size <= 3)
		while (stack_last(*stack_a)->partition == partition)
			rra(stack_a);
	else if (size <= 6)
		twoway_partition(stack_a, stack_b, tmp, size);
	else
		threeway_partition(stack_a, stack_b, tmp, size);
}
