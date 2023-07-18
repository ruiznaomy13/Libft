# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 21:20:17 by ncastell          #+#    #+#              #
#    Updated: 2022/12/31 12:43:59 by ncastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
	ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	ft_strjoin.c ft_strtrim.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c

#SRC_BONUS =

OBJ = ${SRCS:.c=.o}
#OBJBNS = ${SRC_BONUS:.c=.o}
HEADER = libft.h

CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -I libft.h -c $< -o $@

all:		${NAME}

$(NAME):	${OBJ}
			ar crs ${NAME} ${OBJ}

#bonus:		${OBJ} ${OBJBNS} ${HEADER}
#			ar crs ${NAME} ${OBJBNS}
#			@touch $@

clean:		
	${RM} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
