/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:58:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 19:24:28 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	partition(t_stack **stack_a, t_stack **stack_b, int *first_pass)
{
	int	median;
	int	ra_count;
	int	partition_size;

	median = get_median(*stack_a);
	ra_count = 0;
	partition_size = stack_size_partition(*stack_a) / 2;
	while (*stack_a && !(*stack_a)->begin_sorted && ra_count <= partition_size)
	{
		if ((*stack_a)->value > median)
		{
			ra(stack_a);
			ra_count++;
		}
		else
			pb(stack_a, stack_b);
	}
	while (ra_count && !*first_pass)
	{
		rra(stack_a);
		ra_count--;
	}
	*first_pass = 0;
	(*stack_b)->partition = 1;
}

static void	partition_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	median;
	int	rb_count;
	int	partition_size;

	median = get_median(*stack_b);
	rb_count = 0;
	partition_size = stack_size_partition(*stack_b) / 2;
	while (*stack_b && !(*stack_b)->partition && rb_count <= partition_size)
	{
		if ((*stack_b)->value >= median)
			pa(stack_a, stack_b);
		else
		{
			rb(stack_b);
			rb_count++;
		}
	}
	while (rb_count)
	{
		rrb(stack_b);
		rb_count--;
	}
}

static void	push_next_partition(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_b)->partition = 0;
	if (stack_size_partition(*stack_b) <= 3)
	{
		while (*stack_b && !(*stack_b)->partition)
			pa(stack_a, stack_b);
	}
	else
		partition_b_to_a(stack_a, stack_b);
}

/*
static void	push_next_partition(t_stack **stack_a, t_stack **stack_b)
{
	if (!empty(stack_b))
	{
		(*stack_b)->partition = 0;
		while (*stack_b && !(*stack_b)->partition)
			pa(stack_a, stack_b);
	}
}
*/

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	first_pass;

	first_pass = 1;
	while (!sorted(*stack_a) || !empty(stack_b))
	{
		while (stack_size_partition(*stack_a) > 3)
			partition(stack_a, stack_b, &first_pass);
		if (!sorted(*stack_a) && stack_size_partition(*stack_a) > 1)
		{
			if (stack_size(*stack_a) <= 3)
				sort_three(stack_a);
			else
				sort_first_three(stack_a);
		}
		(*stack_a)->begin_sorted = 1;
		if (!empty(stack_b))
			push_next_partition(stack_a, stack_b);
	}
}
