##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##


CFLAGS		=	-I include -Wall -Wextra -g3

CTEST = --coverage -lcriterion

SRC =	sources/main.c	\
		sources/error.c	\
		sources/get_arguments.c	\
		sources/ia.c	\
		sources/init_game.c	\
		sources/player.c	\
		sources/print_map.c	\

OBJ	=	$(SRC:.c=.o)

SRC_RUN_TEST =  tests/tests.c

NAME =	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy\

cleantest:
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

clean:
	rm -f $(OBJ)
	rm -f lib/my/libmy.a

fclean: clean cleantest
	rm -f $(NAME)

unit_tests:
	gcc -o unit_tests $(SRC) $(SRC_RUN_TEST) $(CTEST) -I./include -L ./lib/my -lmy

tests_run: unit_tests
	./unit_tests

branches:
	gcovr --exclude tests/ --branches

coverage:
	gcovr --exclude tests/

re: fclean all

.PHONY: all clean fclean re