# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 12:26:13 by mikferna          #+#    #+#              #
#    Updated: 2022/11/21 11:36:25 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_priint.c \
		ft_printf.c \
		ft_puthexa.c \
		ft_putpu.c \
		ft_utilities.c
		
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Program/Library compiled"

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)
	@echo ".o files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Promgram/Library removed"

re: fclean $(NAME)

.PHONY: all clean fclean re