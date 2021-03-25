# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/13 23:05:47 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:05:33 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lets_make_zombies

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = Zombie.cpp ZombieEvent.cpp main.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
