/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:59:17 by aperin            #+#    #+#             */
/*   Updated: 2022/11/02 14:44:17 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str, int *invalid)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - 48;
		if (sign * nbr < INT_MIN || sign * nbr > INT_MAX)
		{
			*invalid = 1;
			return (0);
		}
		str++;
	}
	if (*str)
		*invalid = 1;
	return (sign * nbr);
}
