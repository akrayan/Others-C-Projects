##
## Makefile for Makefile in /home/rayan/Piscine_CPP/cpp_d01/01
## 
## Made by Rayan
## Login   <raihane.akkache@epitech.net>
## 
## Started on  Wed Jan  4 15:49:09 2017 Rayan
## Last update Fri Mar 17 10:52:57 2017 ernst_m
##

CC	=	gcc

RM	=	rm -rf

NAME	=	philo

SCRS	=	main.c \
		cycle.c

OBJS	=	$(SCRS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

LIB	=	libriceferee.so -lpthread

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
