/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:28:30 by aperin            #+#    #+#             */
/*   Updated: 2022/11/16 11:28:57 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	nb_lower(t_stack *stack, int val, int partition)
{
	int	count;

	count = 0;
	while (stack && stack->partition == partition)
	{
		if (stack->value < val)
			count++;
		stack = stack->next;
	}
	return (count);
}

int	nb_higher(t_stack *stack, int val, int partition)
{
	int	count;

	count = 0;
	while (stack && stack->partition == partition)
	{
		if (stack->value > val)
			count++;
		stack = stack->next;
	}
	return (count);
}