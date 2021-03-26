# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/21 22:19:08 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:12:10 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex02

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp

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
