# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:16:53 by zpalfi            #+#    #+#              #
#    Updated: 2022/11/02 16:48:18 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

#--------------- DIRS ---------------#

INCLUDE_DIR	= include
SRC_DIR		= src
LIBS_DIR	= libs
OBJS_DIR	= objs

#--------------- FILES ---------------#

LIBS			= $(LIBS_DIR)/Libft/libft.a \
				  $(LIBS_DIR)/Get_Next_Line/get_next_line.a \
				  mlx/libmlx.a


LIBS_HEADERS	= -I $(LIBS_DIR)/Libft/include/ \
				  -I $(LIBS_DIR)/Get_Next_Line/include/ \

INC				= -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRC				=	main.c \
					free.c \
					save.c \
					init.c \
					color.c \
					parsers.c \
					rendering.c \
					del_spaces.c \
					map_checker.c \
					height_malloc.c

MLX_DIR		= ./mlx/
MLX_INCLUDE	= -Imlx
MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit
					

OBJ				= $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

#--------------- COMPILATION ---------------#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INC) -Imlx

#--------------- RULES ---------------#

objs/%.o: src/%.c ./include/cub3d.h
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "Compiling $^"

all:	$(NAME)

$(NAME): $(OBJ) $(LIBS) ./include/cub3d.h
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Built $(NAME)"

$(LIBS_DIR)/Libft/libft.a: ./libs/Libft/include/libft.h
	@make -C $(LIBS_DIR)/Libft

$(LIBS_DIR)/Get_Next_Line/get_next_line.a: ./libs/Get_Next_Line/include/get_next_line.h
	@make -C $(LIBS_DIR)/Get_Next_Line

mlx/libmlx.a:
	@make -C mlx/

clean:
	@rm -rf $(OBJS_DIR)

fclean:	clean
	@make fclean -C $(LIBS_DIR)/Libft
	@make fclean -C $(LIBS_DIR)/Get_Next_Line
	@make clean -C mlx
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
