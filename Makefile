# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:30:34 by aperin            #+#    #+#              #
#    Updated: 2022/11/04 10:27:11 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC_FILE	= main.c \
				stack_utils/stack_utils.c \
				utils/ft_atoi.c \
				error/error.c \
				operations/operations.c \
				operations/swap.c \
				operations/push.c \
				operations/rotate.c \
				operations/reverse_rotate.c
				
SRCS_DIR	= srcs
OBJSDIR		= objs

SRCS		= $(addprefix ${SRCS_DIR}/, ${SRC_FILE})
OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${SRC_FILE})))
OBJS_DIR	= $(sort $(dir $(OBJS)))

${OBJSDIR}/%.o: ${SRCS_DIR}/%.c
			@mkdir -p ${OBJSDIR} ${OBJS_DIR}
			gcc -Wall -Wextra -Werror -c -o $@ $<

${NAME}:	${OBJS}
			gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			rm -rf ${OBJS_DIR}
			rm -rf ${OBJSDIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME
