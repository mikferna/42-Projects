# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 16:06:29 by mikferna          #+#    #+#              #
#    Updated: 2023/10/03 12:34:29 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell
DIR_OBJS		=	objs/
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
READLINE 		= -I/Users/$(USER)/.brew/opt/readline/include/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address

RED = \033[1;31m
BLUE = \033[1;36m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

SRCS			=	srcs/00_main.c						\
					srcs/01_checker.c					\
					srcs/02_node_utils.c				\
					srcs/03_minishell.c					\
					srcs/libft/ft_itoa.c				\
					srcs/libft/ft_putchar_fd.c			\
					srcs/libft/ft_putstr_fd.c			\
					srcs/libft/ft_split.c				\
					srcs/libft/ft_strchr.c				\
					srcs/libft/ft_strdup.c				\
					srcs/libft/ft_strjoin.c				\
					srcs/libft/ft_strlen.c				\
					srcs/libft/ft_strncmp.c				\
					srcs/libft/ft_strtrim.c				\
					srcs/libft/ft_substr.c				\
					srcs/builtins/cd.c					\
					srcs/builtins/env_gen.c				\


OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))

# ========= RULES ==========

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)srcs/
	@mkdir -p $(DIR_OBJS)srcs/libft
	@mkdir -p $(DIR_OBJS)srcs/builtins
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PREFIXED)
	@echo "\n$(YELLOW)---------- Compilando Ficheros de Projecto ---------$(RESET)\n"
	@$(CC) $(CFLAGS) $(LREADLINE_FLAGS) $(READLINE) $(LINKS) -o $(NAME) $(PREFIXED)
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