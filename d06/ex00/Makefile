# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/01 13:53:42 by totartar      #+#    #+#                  #
#    Updated: 2021/03/27 11:30:34 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = convert

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = Scalar.cpp int.cpp char.cpp float.cpp double.cpp main.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
		./test.sh
