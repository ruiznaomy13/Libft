# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 21:20:17 by ncastell          #+#    #+#              #
#    Updated: 2024/01/24 16:46:17 by ncastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c  ft_strnstr.c \
		ft_atoi.c ft_strdup.c ft_calloc.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strmapi.c ft_striteri.c ft_itoa.c \
		ft_strjoin.c ft_strtrim.c ft_split.c

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ_DIR	= obj
OBJS	= $(addprefix $(OBJ_DIR)/, ${SRCS:.c=.o})
OBJS_BONUS	= $(addprefix $(OBJ_DIR)/, ${SRCS_BONUS:.c=.o})

DEPS 	= $(addprefix $(OBJ_DIR)/, ${SRCS:.c=.d})
DEPS_BONUS 	= $(addprefix $(OBJ_DIR)/, ${SRCS_BONUS:.c=.d})

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

######## COLORS ########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m

all: ${NAME}

-include	${DEPS} ${DEPS_BONUS}

ifndef BONUS
${NAME}:	${OBJS}
	ar src ${NAME} ${OBJS}
	@echo "$(GREEN)\nLIBFT compiled\n$(NC)"
else	
${NAME}:	${OBJS} ${OBJS_BONUS}
	ar src ${NAME} ${OBJS} ${OBJS_BONUS}
	@echo "$(GREEN)\nBONUS LIBFT compiled\n$(NC)"
endif

${OBJ_DIR}/%.o: %.c ${HEADER} Makefile
	mkdir -p ${OBJ_DIR}
	${CC} -MT $@ ${CFLAGS} -MMD -MP -c $< -o $@

bonus: 
	@make BONUS=1 --no-print-directory
	
clean:
		rm -rf ${OBJ_DIR}
		@echo "$(RED)\nDestruction successful\n$(NC)"

fclean:	clean
		rm -rf ${NAME}

re:	fclean all

.PHONY:	all clean fclean re