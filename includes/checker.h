/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:07:16 by aperin            #+#    #+#             */
/*   Updated: 2022/11/18 19:06:34 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"

# define BUFFER_SIZE 16

// Checker
int		checker(t_stack **stack_a, t_stack **stack_b);

// Get next line
char	*get_next_line(int fd);
char	*gnl_free(char *str1, char *str2);
size_t	ft_strlen(char *str);
int		found_nl(char *str);
char	*strjoin_free(char *save, char *buf, size_t len);

// Utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);

#endif