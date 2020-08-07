# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2020/08/07 20:21:43 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=server

FLAGS= -Wall -Wextra -Werror -g

LIBFT= src/libft/libft.a

INC= -Iinclude

OBJ=src/main.o		src/handler.o\
	src/tcpsocket.o	src/readsocket.o

CFLAGS = $(INC) $(FLAGS)

CC=gcc

all: $(LIBFT)  $(NAME) 

$(NAME): $(HINC) $(OBJ)
	gcc $(INC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	make clean

$(LIBFT):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: fclean all
