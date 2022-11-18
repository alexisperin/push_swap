/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:09:54 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 21:56:16 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_three_max(t_stack *stack)
{
	int	max;
	int	count;

	max = stack->value;
	count = 1;
	while (stack->next && count < 3)
	{
		if (max < stack->next->value)
			max = stack->next->value;
		stack = stack->next;
		count++;
	}
	return (max);
}

static int	stack_three_min(t_stack *stack)
{
	int	min;
	int	count;

	min = stack->value;
	count = 1;
	while (stack->next && count < 3)
	{
		if (min > stack->next->value)
			min = stack->next->value;
		stack = stack->next;
		count++;
	}
	return (min);
}

void	sort_three(t_stack **stack)
{
	if (stack_size(*stack) == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if ((*stack)->value == stack_three_max(*stack))
	{
		ra(stack);
		if (!sorted(*stack))
			sa(stack);
	}
	else if ((*stack)->value == stack_three_min(*stack))
	{
		rra(stack);
		sa(stack);
	}
	else
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		else
			rra(stack);
	}
}

void	sort_first_three(t_stack **stack)
{
	if (stack_size_partition(*stack) == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
		if ((*stack)->next->value == stack_three_max(*stack))
		{
			ra(stack);
			sa(stack);
			rra(stack);
			if (!sorted_partition(*stack))
				sa(stack);
		}
	}
	else
	{
		ra(stack);
		sa(stack);
		rra(stack);
		if (!sorted_partition(*stack))
			sa(stack);
	}
}
