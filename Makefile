# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 20:43:24 by htharrau          #+#    #+#              #
#    Updated: 2024/08/06 12:26:38 by htharrau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables

NAME = push_swap.a
EXEC = push_swap
SRC_DIR = src
SRCS = 0-MAIN.c		0-MFT_SPLIT.c	0-MISC-UTIL.c		1-OPERATIONSa.c		\
	1-OPERATIONSb.c 1-OPERATIONSc.c	2-BEFORE-ALGO.c 	2-STACK-CREATION.c	\
	3-STACK-MISC.c	3-STACK-RANK-INDEX-VALUE.c			3-STACK-SORT.c		\
	3-STACK-SORT2.c	4-MAIN-SORT.c	5-UTIL-ALGO.c		5-UTIL-LIS.c			
SRCS_PATHS = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS_PATHS:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
INCLUDES = -I./includes

# Targets

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(EXEC)  -lm 
	
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re

