# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 16:06:38 by mikferna          #+#    #+#              #
#    Updated: 2024/04/15 13:54:18 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
SRC = main.cpp BitcoinExchange.cpp
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