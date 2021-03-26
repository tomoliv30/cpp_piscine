# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: totartar <totartar@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/23 23:18:34 by totartar      #+#    #+#                  #
#    Updated: 2021/03/26 11:45:07 by totartar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex01

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = AWeapon.cpp  Baguette.cpp  Character.cpp  Enemy.cpp  Knife.cpp \
	Olivier.cpp  PlasmaRifle.cpp  PowerFist.cpp  RadScorpion.cpp \
	SuperMutant.cpp  Tom.cpp Nuke.cpp main.cpp  

all: $(NAME)

COMPILER=clang++

$(NAME):
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

run: fclean all
	./$(NAME)
