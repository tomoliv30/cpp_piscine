# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/19 13:28:22 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:46:07 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fixedTest

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = Fixed.cpp main.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
