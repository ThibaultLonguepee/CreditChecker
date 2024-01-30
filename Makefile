##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Bob the builder builds buildings
##

CC		=	g++

SRC 	=	src/Main.cpp	\
			src/Parser.cpp	\
			src/Displayer.cpp	\

NAME	=	binary

LIBS	=	-lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS	=	$(LIBS) -std=c++20 -Wall -Wextra -Werror -g

TESTFLAGS	=	-fprofile-arcs -ftest-coverage -lcriterion

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -I. -I./tests -o $(NAME)

run:	all
	./$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

#weewoo was here
