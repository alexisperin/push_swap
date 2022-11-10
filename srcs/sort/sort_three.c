/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:09:54 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 17:13:09 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->value == stack_three_max(*stack))
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
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack);
		if ((*stack)->next->value == stack_three_max(*stack))
		{
			ra(stack);
			sa(stack);
			rra(stack);
			if (!sorted(*stack))
				sa(stack);
		}
	}
	else
	{
		ra(stack);
		sa(stack);
		rra(stack);
		if (!sorted(*stack))
			sa(stack);
	}
}
