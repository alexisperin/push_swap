/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:22 by aperin            #+#    #+#             */
/*   Updated: 2022/11/08 19:16:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	twoway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median;
	int	to_push;

	median = get_median(*stack_a);
	to_push = size / 2;
	while (to_push)
	{
		if ((*stack_a)->value <= median)
		{
			pb(stack_a, stack_b);
			to_push--;
		}
		else
			ra(stack_a);
	}
}

static void	threeway_partition(t_stack **stack_a, t_stack **stack_b, int size)
{
	
}

static int	init_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 3)
	{
		sort_three(stack_a);
		return (1);
	}
	else if (size <= 6)
	{
		twoway_partition(stack_a, stack_b, size);
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
		sort_first_three(stack_a);
		return (1);
	}
	else
	{
		threeway_partition(stack_a, stack_b);
		return (0);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (sorted(*stack_a))
		return ;
	if (init_sort(stack_a, stack_b))
		return ;
	return ;
}
