##
## Makefile for Makefile in /home/rayan/Memory/PSU_2016_malloc
## 
## Made by Rayan
## Login   <raihane.akkache@epitech.net>
## 
## Started on  Mon Jan 30 11:28:46 2017 Rayan
## Last update Sat Feb 11 15:23:40 2017 Rayan
##

SRC	= list2.c \
	  malloc.c \
	  malloc2.c \
	  affichage.c \
	  free.c

NAME	= libmy_malloc.so

CFLAGS  = -c -fpic -W -Wall -ansi -pedantic -std=gnu99

CC	= cc

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) -c -fpic $(SRC) $(CFLAGS)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
