/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:58:47 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 11:43:18 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value == stack_max(*stack))
	{
		ra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else if ((*stack)->value == stack_min(*stack))
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
