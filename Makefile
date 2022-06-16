# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 21:00:27 by jfrancis          #+#    #+#              #
#    Updated: 2022/06/15 21:05:16 by jfrancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g -Wall -Wextra -Werror #-fsanitize=address

SRC_DIR = src
UTILS_DIR = utils

OBJ_DIR = build
INCLUDES_DIR = includes

BASE = main.c

UTILS = utils.c

SRC = $(BASE) \
	$(UTILS)

SRC_FULL = $(addprefix $(SRC_DIR)/, $(BASE)) \
	$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS))

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FULL))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)
	$(CC) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	echo cleaning!
	rm -rf $(NAME)
	echo done!

re: fclean all

normi:
	norminette src/*
	norminette includes/*

valgrindfd:
	valgrind --suppressions=readline.supp --track-fds=yes --trace-children=yes ./philo

valgrindleaks:
	valgrind --suppressions=readline.supp --leak-check=full  --show-leak-kinds=all ./philo

.PHONY: all clean fclean re install