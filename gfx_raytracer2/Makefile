##
## Makefile for Makefile in /home/Rayan/Info/gfx_raytracer1
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Sat Mar  5 13:31:40 2016 AKKACHE Kaci
## Last update Tue May 24 13:58:34 2016 AKKACHE Kaci
##

CC		=	gcc

NAME            =       raytracer2

LIB2		=	file_scene/libmy.a

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

FLAG            =       -W -Wall -Werror

SRC             =       main.c			\
			list.c			\
			fill_it.c		\
			tekpixel.c		\
			fcn1.c			\
			fcn2.c			\
			fcn3.c			\
			fcn4.c			\
			fcn5.c			\
			fcn6.c			\
			file_scene/color.c	\
			file_scene/epur.c	\
			file_scene/file_scene.c	\
			file_scene/my_strcmp.c	\
			file_scene/my_strdup.c	\
			file_scene/my_str_to_wordtab.c \
			file_scene/make_cube_face.c \
			file_scene/make_cube_face_bis.c \
			file_scene/make_cmp.c

OBJ             =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) -o $(NAME) $(SRC) $(LIB) $(LIB2)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all fclean re


