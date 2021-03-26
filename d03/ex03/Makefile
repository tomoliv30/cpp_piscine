# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/21 22:21:10 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:10:46 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex03

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp ClapTrap.cpp FragTrap.cpp NinjaTrap.cpp ScavTrap.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
