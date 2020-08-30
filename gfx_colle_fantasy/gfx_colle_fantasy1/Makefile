##
## Makefile for gfx_colle_fantasy1 in /home/assaba_m/rendu/Infographie/gfx_colle_fantasy1
## 
## Made by Moshe Assaban
## Login   <assaba_m@epitech.net>
## 
## Started on  Thu Jan  7 16:21:48 2016 Moshe Assaban
## Last update Thu Jan  7 17:03:30 2016 Moshe Assaban
##

CC		=	gcc

NAME            =       la_forge

LIB             =       -L/home/${USER}/.froot/lib/ -llapin \
                        -L/usr/local/lib \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
                        -lm

FLAG            =       -W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/

SRC             =       main.c

OBJ             =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)

re:		fclean all

.c.o:
	gcc -c $< -o $@ $(FLAG)

