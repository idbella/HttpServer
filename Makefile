# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 22:44:09 by superuser         #+#    #+#              #
#    Updated: 2020/08/06 14:39:44 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=server

all:
	gcc -g main.c libft/libft.a -Ilibft