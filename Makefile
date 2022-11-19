# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:30:34 by aperin            #+#    #+#              #
#    Updated: 2022/11/19 10:53:57 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:	bonus

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
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${B_NAME}:	bonus

bonus:		${NAME} ${B_OBJS}
			# ${CC} ${CFLAGS} ${B_OBJS} -o ${B_NAME}

clean:
			rm -rf ${OBJS_DIR}
			rm -rf ${OBJSDIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME
