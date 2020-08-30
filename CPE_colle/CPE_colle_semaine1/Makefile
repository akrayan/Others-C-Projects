##
## Makefile for make in /home/vella_c/rendu/Prog_elem/CPE_colle_semaine1
## 
## Made by VELLA CYRIL
## Login   <Cyril@epitech.net>
## 
## Started on  Tue Apr 26 18:21:36 2016 VELLA CYRIL
## Last update Tue Apr 26 22:03:16 2016 AKKACHE Kaci
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c		\
		list.c		\
		read.c		\
		my_str.c	\

OBJS	=	$(SRC:.c=.o)

NAME	=	mazesolver

all:		$(NAME) 

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(SRC)

clean:
		$(RM) $(NAME)

fclean:		clean
		$(RM) $(OBJS)

re:		fclean all

.PHONY:		all clean fclean re
