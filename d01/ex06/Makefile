# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 10:03:08 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 10:15:16 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = violence

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)
