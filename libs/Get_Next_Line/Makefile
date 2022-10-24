# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:15:04 by zpalfi            #+#    #+#              #
#    Updated: 2022/10/24 13:54:09 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a

INCLUDE_DIR	= include
SRC_DIR		= src
OBJ_DIR		= obj

INC			= -I $(INCLUDE_DIR)

SRC			= src/get_next_line.c \
			  src/get_next_line_utils.c \

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INC)

OBJ		= $(SRC:%.c=%.o)
CFLAGS	= -Wall -Wextra -Werror -I include
CC		= gcc

$(NAME): $(OBJ) include/get_next_line.h
	@ar rc $(NAME) $(OBJ)
	@echo "Compiling get_next_line.a"

.PHONY : clean
clean:
	@rm -f *.o

.PHONY : fclean
fclean: clean
	@rm -f $(NAME)

.PHONY : all
all: $(NAME)

.PHONY : re
re: fclean all
