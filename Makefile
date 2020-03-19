##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKEFILE
##

SRC			=	src/main.cpp			\

GAMELIB		=	games/hello.cpp			\

GRAPHLIB	=	lib/coco.cpp			\

OBJ	=	$(SRC:.cpp=.o)

CC 	= g++

NAME	=	arcade

RM	=	rm -f

LIB= -fPIC -shared

CPPFLAGS	= -g3

GRAPHLIB=lib_arcade_sfml

GAMELIB=lib_arcade_nibbler

all:	core games graphicals

core:
	$(CC) -o $(NAME) $(SRC) -ldl

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
