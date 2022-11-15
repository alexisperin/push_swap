# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:30:34 by aperin            #+#    #+#              #
#    Updated: 2022/11/15 18:27:15 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
B_NAME		= checker

SRC_FILE	= main.c \
				stack/stack_init.c \
				utils/ft_atoi.c \
				error/error.c \
				operations/operations.c \
				operations/swap.c \
				operations/push.c \
				operations/rotate.c \
				operations/reverse_rotate.c \
				median/median.c \
				partition/twoway_partition.c \
				partition/threeway_partition.c \
				sort/sort_three.c \
				sort/sort_three_utils.c \
				sort/sort_utils.c \
				sort/sort_utils2.c \
				sort/sort.c \

B_FILE	= checker/main_bonus.c
				
SRCS_DIR	= srcs
B_DIR		= srcs
OBJSDIR		= objs

SRCS		= $(addprefix ${SRCS_DIR}/, ${SRC_FILE})
B_SRCS		= $(addprefix ${B_DIR}/, ${B_FILE})
OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${SRC_FILE})))
B_OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${B_FILE})))
OBJS_DIR	= $(sort $(dir $(OBJS)))
B_OBJS_DIR	= $(sort $(dir $(B_OBJS)))

${OBJSDIR}/%.o: ${SRCS_DIR}/%.c
			@mkdir -p ${OBJSDIR} ${OBJS_DIR} ${B_OBJS_DIR}
			gcc -Wall -Wextra -Werror -c -o $@ $<

${NAME}:	${OBJS}
			gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

all:		${NAME}

bonus:		${NAME}
			gcc -Wall -Wextra -Werror ${B_OBJS} -o ${B_NAME}

clean:
			rm -rf ${OBJS_DIR}
			rm -rf ${B_OBJS_DIR}
			rm -rf ${OBJSDIR}

fclean:		clean
			rm -f ${NAME}
			rm -f ${B_NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME bonus
