##
## Makefile for  in /home/vella_c/CPE_colle_semaine4
## 
## Made by VELLA CYRIL
## Login   <Cyril@epitech.net>
## 
## Started on  Tue May 17 18:05:21 2016 VELLA CYRIL
## Last update Tue May 17 21:20:33 2016 AKKACHE Kaci
##

CC	=	gcc -g3

RM	=	rm -f

NAME	=	pokefight

SRCS	=	main.c	\
		str.c	\
		list.c	\
		read.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all re clean fclean
