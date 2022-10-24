# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 14:18:26 by zpalfi            #+#    #+#              #
#    Updated: 2022/10/24 15:48:28 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	src/ft_atoi.c \
			src/ft_calloc.c \
			src/ft_toupper.c \
			src/ft_strrchr.c \
			src/ft_strnstr.c \
			src/ft_strchr.c \
			src/ft_tolower.c \
			src/ft_strdup.c \
			src/ft_strlen.c \
			src/ft_strlcpy.c \
			src/ft_substr.c \
			src/ft_strlcat.c \
			src/ft_strncmp.c \
			src/ft_strrncmp.c \
			src/ft_isdigit.c \
			src/ft_isalpha.c \
			src/ft_isalnum.c \
			src/ft_isascii.c \
			src/ft_isprint.c \
			src/ft_itoa.c \
			src/ft_strmapi.c \
			src/ft_strtrim.c \
			src/ft_memchr.c \
			src/ft_memcmp.c \
			src/ft_putchar_fd.c \
			src/ft_putstr_fd.c \
			src/ft_putendl_fd.c \
			src/ft_putnbr_fd.c \
			src/ft_striteri.c \
			src/ft_split.c \
			src/ft_memcpy.c \
			src/ft_memset.c \
			src/ft_strjoin.c \
			src/ft_memmove.c \
			src/ft_bzero.c \
			src/ft_lstadd_back.c \
			src/ft_lstnew.c \
			src/ft_lstadd_back.c \
			src/ft_lstlast.c \
			
OBJ		= $(SRC:%.c=%.o)
CFLAGS	= -Wall -Wextra -Werror -I include
CC		= gcc

$(NAME): $(OBJ) include/libft.h
	@ar rc $(NAME) $(OBJ)
	@echo "Compiling libft.a"

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