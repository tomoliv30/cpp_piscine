# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/24 09:13:56 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:51:14 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex03

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  main.cpp  MateriaSource.cpp Carbon.cpp

all: $(NAME)

COMPILER=clang++

INCLUDE= -I./

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) $(INCLUDE) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
