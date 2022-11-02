# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:30:34 by aperin            #+#    #+#              #
#    Updated: 2022/11/02 19:45:55 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC_FILE	= main.c \
				stack_utils.c \
				ft_atoi.c

SRCS		= $(addprefix srcs/, ${SRC_FILE})

OBJS		= $(SRCS:.c=.o)

%.o : %.c
			gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
