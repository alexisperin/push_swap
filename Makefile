# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:30:34 by aperin            #+#    #+#              #
#    Updated: 2022/11/23 18:22:17 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
B_NAME		= checker

SRC_FILE	= main.c \
				stack/stack_init.c \
				stack/stack_utils.c \
				stack/stack_utils2.c \
				utils/ft_atoi.c \
				utils/ft_split.c \
				error/error.c \
				operations/operations.c \
				operations/swap.c \
				operations/push.c \
				operations/rotate.c \
				operations/reverse_rotate.c \
				median/median.c \
				sort/sort_three.c \
				sort/sort.c \
				partition/partition_a.c \
				partition/partition_a_end.c \
				partition/partition_b.c \
				partition/partition_b_end.c

B_SRC_FILE	= main_bonus.c \
				checker/checker.c \
				stack/stack_init.c \
				stack/stack_utils.c \
				stack/stack_utils2.c \
				utils/ft_atoi.c \
				utils/ft_split.c \
				utils/ft_strncmp.c \
				error/error.c \
				operations/operations.c \
				operations/swap.c \
				operations/push.c \
				operations/rotate.c \
				operations/reverse_rotate.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c
				
SRCS_DIR	= srcs
OBJSDIR		= objs
INCDIR		= includes

SRCS		= $(addprefix ${SRCS_DIR}/, ${SRC_FILE})
B_SRCS		= $(addprefix ${SRCS_DIR}/, ${B_SRC_FILE})
OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${SRC_FILE})))
B_OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${B_SRC_FILE})))
OBJS_DIR	= $(sort $(dir $(OBJS)))
B_OBJS_DIR	= $(sort $(dir $(B_OBJS)))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I ${INCDIR}

${OBJSDIR}/%.o: ${SRCS_DIR}/%.c
			@mkdir -p ${OBJSDIR} ${OBJS_DIR} ${B_OBJS_DIR}
			${CC} ${CFLAGS} ${INCS} -c -o $@ $<

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

${B_NAME}:	${B_OBJS}
			${CC} ${B_OBJS} -o ${B_NAME}

bonus:		${B_NAME}	

clean:
			rm -rf ${OBJSDIR}

fclean:		clean
			rm -f ${NAME}
			rm -f ${B_NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME bonus B_NAME
