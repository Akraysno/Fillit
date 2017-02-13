# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 14:09:05 by gauffret          #+#    #+#              #
#    Updated: 2016/12/05 14:09:11 by gauffret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRC_PATH	=	src

OBJ_PATH	=	obj

SRC_NAME	=	main.c \
				ft_check_file.c \
				ft_check_form.c \
				ft_fillit.c \
				backtrack.c \
				ft_createpiece.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbrendl.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strsplit.c \
				ft_strdel.c \
				ft_strsub.c \
				ft_isupper.c \
				ft_secondary_fonction.c \
				ft_memdel.c
				
OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH	=	includes

INCL		=	-I$(INC_PATH)

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

.PHONY : all, clean, fclean, re, norme

all :	$(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCL)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(INCL)

clean :
	rm -rf $(OBJ)

fclean :	clean
	rm -rf $(NAME)

re :	fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h