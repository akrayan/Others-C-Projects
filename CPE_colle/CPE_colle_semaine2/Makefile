##
## Makefile for make in /home/vella_c/CPE_colle_semaine2
## 
## Made by VELLA CYRIL
## Login   <Cyril@epitech.net>
## 
## Started on  Tue May  3 18:08:53 2016 VELLA CYRIL
## Last update Tue May  3 21:34:42 2016 AKKACHE Kaci
##

CC	=	gcc

RM	=	rm

SRC	=	main.c \

LIB	=	-lncurses

OBJ	=	$(SRC:.c=.o)

NAME	=	sakabels

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(LIB)

clean:	
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
