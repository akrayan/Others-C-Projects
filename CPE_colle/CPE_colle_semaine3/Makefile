##
## Makefile for Makefile in /home/Rayan/Colle
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Tue May 10 18:13:48 2016 AKKACHE Kaci
## Last update Tue May 10 18:20:03 2016 AKKACHE Kaci
##

CC = gcc

RM = rm -f

NAME = guacamole

SCR = main.c

OBJ = $(SCR:.c=.o)

LIB = -L/home/${USER}/.froot/lib/ -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(SCR) $(LIB)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
