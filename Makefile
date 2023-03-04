# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:02:29 by hsaadi            #+#    #+#              #
#    Updated: 2022/09/23 12:25:21 by hsaadi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/
SRCS_PATH = src/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS_FILES = push_swap.c logs.c tools.c utils.c check_args.c stack_ops.c sorting_five.c sorting_three.c allowed_ops.c\
			 hundreds_sort_v1.c hund_utils.c \

SRCS_FILES_BONUS = checker.c logs.c tools.c utils.c check_args.c stack_ops.c sorting_five.c sorting_three.c allowed_ops.c\
			 hundreds_sort_v1.c hund_utils.c  \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)


SRCS_BONUS = $(addprefix $(SRCS_PATH), $(SRCS_FILES_BONUS))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
		

all: 	$(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

$(NAME): $(OBJS)
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"


clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)💯"

fclean:	clean
	@$(RM) $(NAME) $(BONUS_NAME) $(LIBFT)

re:		fclean all

bonus: 	$(BONUS_NAME)
	@echo "BOOM 💥💥💥💥💥 $(BONUS_NAME) Compiled! 💯 $(DEFAULT)"

$(BONUS_NAME): $(OBJS_BONUS)
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo "$(GREEN)$(BONUS_NAME) created!$(DEFAULT)"


help:
	@echo "This is help "
	
git:
	@git add .
	@git commit -m "$(message)"
	@git push
	@echo "\n$(GREEN)$(message) Committed!$(DEFAULT)💯"
	
#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
message = "Commit Message By Default On $(shell date "+%d %B %T")"

.PHONY:	all clean libft fclean re message
