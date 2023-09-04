# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 15:08:09 by mikferna          #+#    #+#              #
#    Updated: 2023/09/04 16:16:37 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra #-g3 -fsanitize=address

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

SRCS			=	srcs/main.c							\
					srcs/checkers.c						\
					srcs/node.c							\
					srcs/functions.c					\
					srcs/movements.c					\
					srcs/doublemovements.c				\
					srcs/algorithm.c					\
					srcs/algorithm2.c					\
					srcs/free.c							\
					srcs/libft/ft_split.c				\
					srcs/libft/ft_strlen.c				\
					srcs/libft/ft_substr.c				\
					srcs/libft/ft_strdup.c				\
					srcs/libft/ft_strlcpy.c				\
					srcs/libft/ft_memcpy.c				\
					srcs/libft/ft_atoi.c				\


OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))

# ========= RULES ==========

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs
	@mkdir -p $(DIR_OBJS)/srcs/libft
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PREFIXED)
	@echo "\n$(YELLOW)---------- Compilando Ficheros de Projecto ---------$(RESET)\n"
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)All deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re