/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:58:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/15 17:12:35 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	twoway_partition2(t_stack **stack_b, int partition)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp && tmp->partition == partition)
	{
		tmp->partition = (partition * 3);
		tmp = tmp->next;
	}
	tmp = stack_last(*stack_b);
	if (!stack_only_one_partition(*stack_b))
	{
		while (tmp->partition == (partition * 3))
		{
			rrb(stack_b);
			tmp = stack_last(*stack_b);
		}
	}
}

static void	push_next_partition2(t_stack **stack_a, t_stack **stack_b)
{
	int		size = stack_size_partition(*stack_b);
	int		median;
	int		to_push;
	int		partition;

	median = get_median(*stack_b);
	// printf("median: %d\n", median);
	to_push = size / 2 + size % 2;
	partition = (*stack_b)->partition;
	while (to_push > 0)
	{
		if ((*stack_b)->value >= median)
		{
			(*stack_b)->partition = (partition * 3) + 1;
			pa(stack_a, stack_b);
			to_push--;
		}
		else
		{
			(*stack_b)->partition = partition * 3;
			rb(stack_b);
		}
	}
	twoway_partition2(stack_b, partition);
}

static void	push_next_partition(t_stack **stack_a, t_stack **stack_b)
{
	int	partition;

	// printf("Before\n");
	// printf("---Stack A---\n");
	// print_stack(*stack_a);
	// printf("---Stack B---\n");
	// print_stack(*stack_b);
	if (stack_size_partition(*stack_b) <= 3)
	{
		partition = (*stack_b)->partition;
		while (*stack_b && (*stack_b)->partition == partition)
			pa(stack_a, stack_b);
	}
	else
		push_next_partition2(stack_a, stack_b);
	// printf("After\n");
	// printf("---Stack A---\n");
	// print_stack(*stack_a);
	// printf("---Stack B---\n");
	// print_stack(*stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	partition_size;

	while (!sorted(*stack_a) || !empty(stack_b))
	{
		partition_size = stack_size_partition(*stack_a);
		while (partition_size > 6)
		{
			threeway_partition(stack_a, stack_b, partition_size);
			partition_size = stack_size_partition(*stack_a);
		}
		if (partition_size > 3)
			twoway_partition(stack_a, stack_b, partition_size);
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
