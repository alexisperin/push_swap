/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:33:48 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 14:59:04 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
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
	sort(&stack_a, &stack_b);
	if (sorted(stack_a))
		printf("SORTED\n");
	else
		printf("NOT SORTED\n");
	printf("---Stack A---\n");
	print_stack(stack_a);
	printf("---Stack B---\n");
	print_stack(stack_b);
	free_stack(stack_a);
	// free_stack(stack_b);
	return (0);
}
