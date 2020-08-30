##
## Makefile for Makefile in /home/assaba_m/RENDU/SEM2/Infographie/gfx_scroller
## 
## Made by assaba_m
## Login   <assaba_m@epitech.net>
## 
## Started on  Fri Mar 18 20:04:12 2016 assaba_m
## Last update Wed May 18 19:02:14 2016 Afou Nacerdine
##

CC		=	gcc

NAME            =       colle1

LIB             =       -L/home/${LOGNAME}/.froot/lib/ -llapin \
                        -L/usr/local/lib \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
                        -lm

CFLAGS          =        -W -Wall -Werror -I/home/${LOGNAME}/.froot/include/

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

