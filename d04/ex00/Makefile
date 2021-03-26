# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/23 14:44:42 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:41:35 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex00

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = Dada.cpp Dodo.cpp Peon.cpp Sorcerer.cpp Victim.cpp main.cpp

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
