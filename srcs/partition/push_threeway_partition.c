/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_threeway_partition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:06:24 by aperin            #+#    #+#             */
/*   Updated: 2022/11/17 09:41:07 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_third_max(t_stack *stack_b)
{
	t_stack	*tmp;
	int		partition;

	tmp = stack_b;
	partition = stack_b->partition;
	while (tmp && tmp->partition == partition)
	{
		if (nb_higher(stack_b, tmp->value, partition) == 2)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}

static void	push_low(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_b)->partition *= 3;
	(*stack_b)->partition += 1;
	pa(stack_a, stack_b);
	ra(stack_a);
	(*to_push)--;
}

static void	push_high(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_b)->partition *= 3;
	(*stack_b)->partition += 2;
	pa(stack_a, stack_b);
	(*to_push)--;
}

static void	push_threeway_part2(t_stack **stack_a, t_stack **stack_b, int part)
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
	if (!sorted_partition(*stack_a))
		sort_first_three(stack_a);
	stack_set_sorted(*stack_a);
	tmp = stack_last(*stack_a);
	while (tmp && tmp->partition == (part * 3) + 1)
	{
		rra(stack_a);
		tmp = stack_last(*stack_a);
	}
}

void	push_threeway_partition(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		third_max;
	int		size;
	int		to_push;
	int		partition;

	median = get_median_bis(*stack_b);
	third_max = get_third_max(*stack_b);
	size = stack_size_partition(*stack_b);
	to_push = 3 + ((size - 3) / 2) + (size - 3) % 2;
	partition = (*stack_b)->partition;
	while (to_push > 0)
	{
		if ((*stack_b)->value >= third_max)
			push_high(stack_a, stack_b, &to_push);
		else if ((*stack_b)->value >= median)
			push_low(stack_a, stack_b, &to_push);
		else
		{
			(*stack_b)->partition = partition * 3;
			rb(stack_b);
		}
	}
	push_threeway_part2(stack_a, stack_b, partition);
}

// void	push_threeway_partition(t_stack **stack_a, t_stack **stack_b)
// {
// 	push_twoway_partition(stack_a, stack_b);
// }
