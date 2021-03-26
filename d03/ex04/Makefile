# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/21 23:01:54 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:07:37 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex04

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp SuperTrap.cpp ClapTrap.cpp FragTrap.cpp NinjaTrap.cpp ScavTrap.cpp 

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) $(INCLUDE) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
