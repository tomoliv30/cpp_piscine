# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/23 23:25:18 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:46:27 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex02

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = AssaultTerminator.cpp  main.cpp  Squad.cpp  TacticalMarine.cpp

all: $(NAME)

COMPILER=clang++

INCLUDE= -I./

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)
	chmod 755 ./$(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
