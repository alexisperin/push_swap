/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threeway_partition_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:39:42 by aperin            #+#    #+#             */
/*   Updated: 2022/11/10 18:43:08 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_low(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_a)->partition = (partition * 3) + 2;
	pb(stack_a, stack_b);
	rb(stack_b);
	to_push--;
}

void	push_high(t_stack **stack_a, t_stack **stack_b, int *to_push)
{
	(*stack_a)->partition = (partition * 3) + 1;
	pb(stack_a, stack_b);
	to_push--;
}
