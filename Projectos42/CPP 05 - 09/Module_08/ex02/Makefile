# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 13:53:04 by mikferna          #+#    #+#              #
#    Updated: 2024/03/19 13:56:15 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
CC = c++ -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	@echo "Compiling: $<"
	@$(CC) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "Objects cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable cleaned!"

re: fclean all

.PHONY: all clean fclean re