/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:33:48 by aperin            #+#    #+#             */
/*   Updated: 2022/11/04 14:05:47 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = init_stack(ac, av);
	if (!stack_a)
		return (print_error());
	printf("%d\n", median(stack_a));
	// sort_3(&stack_a);
	// print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
