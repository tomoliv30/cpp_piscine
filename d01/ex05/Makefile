# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 09:52:05 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:14:56 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = hi_brain

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp Brain.cpp Human.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
