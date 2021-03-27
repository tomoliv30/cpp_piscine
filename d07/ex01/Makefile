# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 11:55:16 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 15:37:50 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = iter

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp Emoji.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
