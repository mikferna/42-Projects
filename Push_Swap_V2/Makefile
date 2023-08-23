# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 15:08:09 by mikferna          #+#    #+#              #
#    Updated: 2023/08/23 11:59:04 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address
//LINKS			=	-L . -lmlx -framework OpenGL -framework AppKit

SRCS			=	srcs/main.c							\
					srcs/checkers.c						\
					srcs/node.c							\
					srcs/functions.c					\
					srcs/movements.c					\
					srcs/doublemovements.c				\
					srcs/algorithm.c					\
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

$(NAME) : print $(PREFIXED)
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"

# ========== FUNCTIONS ==========

print:
	@echo "\n$(YELLOW)---------- Compilando Ficheros de Projecto ---------$(RESET)\n"

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "\n${BLUE}Cleaned!${RESET}\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print