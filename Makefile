# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporzier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:02:59 by mporzier          #+#    #+#              #
#    Updated: 2018/12/10 14:41:53 by mporzier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
### OPTIONS
###############################################################################

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
GRAPHFLAGS = -lmlx -framework OpenGL -framework AppKit

###############################################################################
### COLORS
###############################################################################

COL_BLACK		= \033[1;30m
COL_RED			= \033[1;31m
COL_GREEN		= \033[1;32m
COL_YELLOW		= \033[1;33m
COL_BLUE		= \033[1;34m
COL_PURPLE		= \033[1;35m
COL_WHITE		= \033[1;37m

###############################################################################
### SOURCES
###############################################################################

SRC =	bresenham.c	buildlstcav.c buildlstiso.c checkerrors.c colors.c ft_atoi.c\
		genericfunc.c get_next_line.c keyevents.c main.c printlist.c ft_strchr.c\
		ft_strjoin.c ft_strlen.c ft_strndup.c ft_strnew.c ft_strsub.c

###############################################################################
### RULES
###############################################################################

OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(GRAPHFLAGS)
	@echo "$(COL_GREEN)$(NAME)			created !"

%.o : %.c
	@$(CC) $(CFLAGS) -c $? -o $@
	@echo "$(COL_PURPLE)$@		created !"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "$(COL_YELLOW)Objects 		deleted !"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COL_RED)$(NAME) 		deleted !"

re: fclean all
