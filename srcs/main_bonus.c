/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:11 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 18:50:15 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d, part: %d\n", stack->value, stack->partition);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = init_stack(ac, av);
	if (!stack_a)
		return (print_error());
	stack_b = 0;
	if (checker(&stack_a, &stack_b) == -1)
		write(1, "KO\n", 3);
	if (sorted(stack_a) && empty(&stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// printf("---Stack A---\n");
	// print_stack(stack_a);
	// printf("---Stack B---\n");
	// print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
