# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/08 10:20:52 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 15:46:20 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp mutantstack.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
