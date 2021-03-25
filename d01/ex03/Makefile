# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 00:03:38 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:07:19 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lets_make_zombie_horde

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp ZombieHorde.cpp Zombie.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
