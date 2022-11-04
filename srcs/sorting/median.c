/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:54:33 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 14:07:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	nb_lower(t_stack *stack, int val)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->value < val)
			count++;
		stack = stack->next;
	}
	return (count);
}

static int	nb_higher(t_stack *stack, int val)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->value > val)
			count++;
		stack = stack->next;
	}
	return (count);
}

int	median(t_stack *stack)
{
	t_stack	*tmp;
	int		lower;
	int		higher;

	if (!stack->next)
		return (stack->value);
	tmp = stack;
	while (tmp)
	{
		lower = nb_lower(stack, tmp->value);
		higher = nb_higher(stack, tmp->value);
		if (lower == higher || lower + 1 == higher)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}
