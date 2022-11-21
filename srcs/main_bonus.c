/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:11 by aperin            #+#    #+#             */
/*   Updated: 2022/11/21 15:30:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (ac == 2)
		stack_a = init_stack(ft_split(av[1], ' '), 0);
	else
		stack_a = init_stack(av, 1);
	if (!stack_a)
		return (print_error());
	stack_b = 0;
	if (checker(&stack_a, &stack_b) == -1)
		print_error();
	else if (sorted(stack_a) && empty(&stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
