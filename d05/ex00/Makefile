# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 12:32:56 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:57:09 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = d05ex00

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = Bureaucrat.cpp main.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) $(INCLUDE) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
