# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/07 14:01:09 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 15:41:55 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = itemNotFound.cpp main.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
