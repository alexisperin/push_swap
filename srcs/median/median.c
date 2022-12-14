/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:54:33 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 21:56:16 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nb_lower(t_stack *stack, int val, int partition)
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

static int	nb_higher(t_stack *stack, int val, int partition)
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

int	get_median(t_stack *stack)
{
	t_stack	*tmp;
	int		partition;
	int		lower;
	int		higher;

	if (!stack->next)
		return (stack->value);
	tmp = stack;
	partition = tmp->partition;
	while (tmp && tmp->partition == partition)
	{
		lower = nb_lower(stack, tmp->value, partition);
		higher = nb_higher(stack, tmp->value, partition);
		if (lower == higher || lower == higher + 1)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}

int	get_median_low(t_stack *stack)
{
	t_stack	*tmp;
	int		partition;
	int		partition_size;

	if (!stack->next)
		return (stack->value);
	tmp = stack;
	partition = tmp->partition;
	partition_size = stack_size_partition(stack);
	while (tmp && tmp->partition == partition)
	{
		if (nb_lower(stack, tmp->value, partition) == partition_size / 3)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}

int	get_median_high(t_stack *stack)
{
	t_stack	*tmp;
	int		partition;
	int		partition_size;

	if (!stack->next)
		return (stack->value);
	tmp = stack;
	partition = tmp->partition;
	partition_size = stack_size_partition(stack);
	while (tmp && tmp->partition == partition)
	{
		if (nb_higher(stack, tmp->value, partition) == partition_size / 3)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}
