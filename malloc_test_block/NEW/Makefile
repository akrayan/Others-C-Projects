##
## Makefile for Makefile in /home/rayan/Memory/PSU_2016_malloc
## 
## Made by Rayan
## Login   <raihane.akkache@epitech.net>
## 
## Started on  Mon Jan 30 11:28:46 2017 Rayan
## Last update Thu Feb  9 11:12:09 2017 Axel
##

SRC	= list2.c \
	  malloc.c \
	  affichage.c
NAME	= libmy_malloc.so

CFLAGS  = -c -fpic -W -Wall -ansi -pedantic -std=gnu99

CC	= cc -g3

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
