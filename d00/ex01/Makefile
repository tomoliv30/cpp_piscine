# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 14:46:47 by totartar      #+#    #+#                  #
#    Updated: 2021/03/25 09:46:03 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = crap

FLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic

SRC = main.cpp Contact.cpp Phonebook.cpp

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -g -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
