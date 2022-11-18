/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:49:22 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 19:24:12 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	do_operation2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rra\n", 4) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rrb\n", 4) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strlen(line) == 4 && ft_strncmp(line, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
	else
		return (-1);
	return (0);
}

static int	do_operation(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strlen(line) == 3 && ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap(*stack_a);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap(*stack_b);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "ss\n", 3) == 0)
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
	}
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "pa\n", 3) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "pb\n", 3) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strlen(line) == 3 && ft_strncmp(line, "rr\n", 3) == 0)
		{
			ft_rotate(stack_a);
			ft_rotate(stack_b);
		}
	else
		return (do_operation2(stack_a, stack_b, line));
	return (0);
}

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		ret;

	line = get_next_line(0);
	ret = 0;
	while (line)
	{
		if (do_operation(stack_a, stack_b, line) == -1)
			ret = -1;
		free(line);
		line = get_next_line(0);
	}
	return (ret);
}
