# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/19 13:28:50 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:48:36 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fixedTest_ex01

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
