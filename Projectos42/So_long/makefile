# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:49:26 by mikferna          #+#    #+#              #
#    Updated: 2023/02/15 13:53:03 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
LINKS			=	-L . -lmlx -framework OpenGL -framework AppKit

SRCS			=	srcs/main.c								\
					srcs/check_command.c					\
					srcs/mapa.c								\
					srcs/funciones.c						\
					srcs/gnl/get_next_line.c				\
					srcs/gnl/get_next_line_utils.c			\

OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))

# ========= RULES ==========

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs
	@mkdir -p $(DIR_OBJS)/srcs/gnl
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : print $(PREFIXED)
	@$(MAKE) -C ./minilibx
	@cp ./minilibx/libmlx.a .
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"

# ========== FUNCTIONS ==========

print:
	@echo "\n$(YELLOW)---------- Compilando Ficheros de Projecto ---------$(RESET)\n"

all: $(NAME)

clean:
	@$(MAKE) -C ./minilibx clean
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "\n${BLUE}Cleaned!${RESET}\n"

fclean: clean
	@$(RM) libmlx.a
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print
