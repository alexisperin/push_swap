/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_partition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:43:28 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 09:52:56 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_high(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_b)->partition *= 3;
	(*stack_b)->partition += 2;
	pa(stack_a, stack_b);
	(*to_push)--;
}

static void	push_low(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_b)->partition *= 3;
	(*stack_b)->partition += 1;
	pa(stack_a, stack_b);
	ra(stack_a);
	(*to_push)--;
}

static void	push_threeway_part2(t_stack **stack_b, int part)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp && tmp->partition == part)
	{
		tmp->partition = part * 3;
		tmp = tmp->next;
	}
	if (!stack_only_one_partition(*stack_b))
	{
		tmp = stack_last(*stack_b);
		while (tmp->partition == part * 3)
		{
			rrb(stack_b);
			tmp = stack_last(*stack_b);
		}
	}
}

void	push_threeway_partition(t_stack **stack_a, t_stack **stack_b)
{
	int		median_low;
	int		median_high;
	int		size;
	int		to_push;
	int		partition;

	median_low = get_median_low(*stack_b);
	median_high = get_median_high(*stack_b);
	size = stack_size_partition(*stack_b);
	to_push = ((size / 3) * 2) + (size % 3);
	partition = (*stack_b)->partition;
	while (to_push > 0)
	{
		if ((*stack_b)->value > median_high)
			push_high(stack_a, stack_b, &to_push);
		else if ((*stack_b)->value >= median_low)
			push_low(stack_a, stack_b, &to_push);
		else
		{
			(*stack_b)->partition = partition * 3;
			rb(stack_b);
		}
	}
	push_threeway_part2(stack_b, partition);
}

// void	push_threeway_partition(t_stack **stack_a, t_stack **stack_b)
// {
// 	push_twoway_partition(stack_a, stack_b);
// }
