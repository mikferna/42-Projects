NAME			=	push_swap
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address
//LINKS			=	-L . -lmlx -framework OpenGL -framework AppKit

SRCS			=	srcs/ps_main.c							\
					srcs/ps_checker.c						\
					srcs/ps_checker2.c						\
					srcs/ps_init.c							\
					srcs/libft/ft_atoi.c					\
					srcs/libft/ft_split.c					\
					srcs/libft/ft_substr.c					\
					srcs/libft/ft_strlen.c					\
					srcs/libft/ft_strlcpy.c					\
					srcs/libft/ft_strdup.c					\
					srcs/libft/ft_memcpy.c					\

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