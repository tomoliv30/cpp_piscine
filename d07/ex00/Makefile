# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 11:52:07 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 15:31:51 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = whatever

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
