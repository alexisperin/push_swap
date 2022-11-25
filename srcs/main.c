/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:33:48 by aperin            #+#    #+#             */
/*   Updated: 2022/11/25 08:33:22 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2 || (ac == 2 && av[1][0] == 0))
		return (0);
	if (ac == 2)
		stack_a = init_stack(ft_split(av[1], ' '), 0);
	else
		stack_a = init_stack(av, 1);
	if (!stack_a)
		return (print_error());
	stack_b = 0;
	sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
