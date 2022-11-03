/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:33:48 by aperin            #+#    #+#             */
/*   Updated: 2022/11/03 08:55:36 by aperin           ###   ########.fr       */
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
	t_stack	*stack_b;
	char	*strs[5] = {"a.out", "3", "-5", "1", "10"};

	if (ac < 2)
		return (0);
	stack_a = init_stack(ac, av);
	if (!stack_a)
		return (print_error());
	stack_b = init_stack(5, strs);
	printf("Stack a\n");
	print_stack(stack_a);
	printf("Stack b\n");
	print_stack(stack_b);
	rr(&stack_a, &stack_b);
	printf("Stack a\n");
	print_stack(stack_a);
	printf("Stack b\n");
	print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
