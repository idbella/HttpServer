# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: superuser <superuser@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 16:23:12 by sid-bell          #+#    #+#              #
#    Updated: 2020/07/13 16:33:42 by superuser        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

OFILES=ft_atoi.o ft_bzero.o ft_csd.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
ft_isdigit.o ft_isprint.o ft_isspace.o ft_itoa.o ft_lstadd.o ft_lstcount.o ft_lstdel.o\
ft_lstdelone.o ft_lstfold.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_lstprint.o ft_memalloc.o\
ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_putendl_fd.o\
ft_memset.o ft_nbrlen.o ft_printf.o ft_putchar.o ft_putchar_fd.o ft_putendl.o\
ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o\
ft_strcmp.o ft_strcount.o ft_strcpy.o ft_strctrim.o ft_strdel.o ft_strdup.o ft_strequ.o\
ft_striter.o ft_striteri.o ft_strjoin.o ft_strlen.o ft_strmap.o ft_gethex.o ft_getflags.o\
ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strndup.o ft_strnequ.o ft_strnew.o\
ft_strnstr.o ft_strpos.o ft_strrchr.o ft_strrepeat.o ft_strreplace.o ft_strrev.o ft_strsplit.o\
ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o get_next_line.o ft_free_array.o \
ft_fstrjoin.o ft_fstrsub.o ft_join.o ft_isalphanum.o ft_isnumber.o ft_arraylen.o

CFLAGS = -g -Wall -Wextra -Werror -I../include

all : $(NAME)

$(NAME) : $(OFILES)
	@ar rc $(NAME) $(OFILES)

clean :
	@rm -rf $(OFILES)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
