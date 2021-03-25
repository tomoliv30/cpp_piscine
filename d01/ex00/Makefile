# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/17 16:36:45 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:04:16 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lets_make_ponies

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = Pony.cpp main.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
