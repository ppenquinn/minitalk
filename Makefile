# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nappalav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 23:28:39 by nappalav          #+#    #+#              #
#    Updated: 2024/06/27 18:29:50 by nappalav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
CC = cc
RM = rm
# CFLAGS = -Wall -Wextra -Werror
RMFLAGS = -f

LIB = ./resource/libprintf.a

SRC_S = server.c
SRC_C = client.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all:	$(NAME_S) $(NAME_C)

$(NAME_S):$(OBJ_S)
	${MAKE} -C ./resource/libft
	${MAKE} -C ./resource/libft bonus
	${MAKE} -C ./resource/ft_printf
	$(CC) $(CFLAGS) $(OBJ_S) $(LIB) -o $(NAME_S)
	# clear

$(NAME_C):$(OBJ_C)
	${MAKE} -C ./resource/libft
	${MAKE} -C ./resource/libft bonus
	${MAKE} -C ./resource/ft_printf
	$(CC) $(CFLAGS) $(OBJ_C) $(LIB) -o $(NAME_C)
	# clear

clean:
	${MAKE} -C ./resource/libft fclean
	${MAKE} -C ./resource/ft_printf fclean
	$(RM) $(RMFLAGS) $(OBJ_C) $(OBJ_S)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME_C) $(NAME_S)

re:	fclean all

.PHONY: re clean fclean all
