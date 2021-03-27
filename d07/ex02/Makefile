# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 12:10:25 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 15:35:41 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex02

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp Emoji.cpp

COMPILER=clang++

all: $(NAME)

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
