# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#    Updated: 2016/01/16 11:31:01 by rmc-coma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a

HDR = ./fillit.h

SRCS = main.c \
	   ft_validate_tetrifile.c \
	   ft_extract_tetriminos.c \
	   ft_file_len.c \
	   ft_solve.c \
	   ft_puttetrimap.c \
	   ft_create_tetrimap.c \
	   ft_upscale_tetrimap.c \
	   ft_get_tetriminos_n.c

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@echo "\033[0;36m                            \033[0m"
	@echo "\033[0;36m  _______ __ __ __ __ __    \033[0m"
	@echo "\033[0;36m |    ___|__|  |  |__|  |_  \033[0m"
	@echo "\033[0;36m |    ___|  |  |  |  |   _| \033[0m"
	@echo "\033[0;36m |___|   |__|__|__|__|____| \033[0m"
	@echo "\033[0;36m                            \033[0m"
	@echo "\033[1;30m Compiling...               \033[0m"
	@make -C ./libft
	@$(CC) $(CFLAGS) -I $(HDR) -c $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ)
	@echo "\033[0;36m Fillit binary compiled     \033[0m"

clean:
	-@rm -f $(OBJ)
	-@make -C ./libft clean
	-@echo "\033[0;36m Objects removed           \033[0m"

fclean: clean
	-@rm -f $(NAME)
	-@make -C ./libft fclean
	-@echo "\033[0;36m Filit binary removed      \033[0m"

re: fclean all
	-@make -C ./libft re
