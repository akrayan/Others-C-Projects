##
## Makefile for Makefile in /home/Rayan/Info/gfx_raytracer1
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Sat Mar  5 13:31:40 2016 AKKACHE Kaci
## Last update Sun May 22 19:21:51 2016 AKKACHE Kaci
##

CC		=	gcc

NAME            =       raytracer2

LIB             =       -I/home/${USER}/.froot/include		\
			-L/home/${USER}/.froot/lib/		\
			-llapin					\
                        -L/usr/local/lib			\
                        -lsfml-audio				\
                        -lsfml-graphics				\
                        -lsfml-window				\
                        -lsfml-system				\
                        -lstdc++ -ldl				\
                        -lm					\
			./lib/my/libmy.a

FLAG            =       -W -Wall -Werror

SRC             =       main.c			\
			sphere.c		\
			./tcore/tekpixel.c	\
			./tcore/tekray.c

OBJ             =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) -o $(NAME) $(SRC) $(LIB) $(FLAG)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all fclean re


