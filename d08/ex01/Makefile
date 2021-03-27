# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/09 14:26:36 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 15:45:50 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = span

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = span.cpp main.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
