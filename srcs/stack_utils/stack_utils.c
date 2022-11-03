/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:47:08 by aperin            #+#    #+#             */
/*   Updated: 2022/11/03 11:16:20 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (0);
}

static int	is_duplicate(int val, t_stack *stack)
{
	while (stack && stack->value != val)
		stack = stack->next;
	if (stack && stack->next && stack->value == val)
		return (1);
	return (0);
}

static t_stack	*stack_new(const char *str)
{
	t_stack	*stack;
	int		invalid;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	invalid = 0;
	stack->value = ft_atoi(str, &invalid);
	if (invalid)
	{
		free(stack);
		return (0);
	}
	stack->next = 0;
	return (stack);
}

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = stack_new(av[1]);
	tmp = stack_a;
	if (!stack_a)
		return (0);
	i = 2;
	while (i < ac)
	{
		tmp->next = stack_new(av[i]);
		if (!tmp->next || is_duplicate(tmp->next->value, stack_a))
			return (free_stack(stack_a));
		tmp = tmp->next;
		i++;
	}
	return (stack_a);
}
