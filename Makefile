##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKEFILE
##

SRC			=	src/main.cpp			\
				src/Core.cpp			\

OBJ	=	$(SRC:.cpp=.o)

CC 	= g++

NAME	=	arcade

RM	=	rm -f

LIB= -fPIC -shared -lncurses

CPPFLAGS	= -g3

GRAPHLIB=lib_arcade_ncurse #lib_arcade_sfml

GAMELIB=lib_arcade_nibbler lib_arcade_pacman

all:	core games graphicals

core:
	$(CC) -o $(NAME) $(SRC) -ldl -g3

games: $(GAMELIB)

%: games/%.cpp
	$(CC) $^ $(LIB) -o $@.so

graphicals: $(GRAPHLIB)

%: lib/%.cpp
	$(CC) $^ $(LIB) -o $@.so

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) *.so

re:	fclean all

.PHONY:	all re fclean clean
