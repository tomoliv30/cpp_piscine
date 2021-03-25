# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 08:47:06 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:13:46 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = brain

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = ex04.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
