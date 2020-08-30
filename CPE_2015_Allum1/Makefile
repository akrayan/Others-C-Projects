##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Sun Feb 21 09:30:24 2016 AKKACHE Kaci
##

CC= 	gcc -g3

RM= 	rm -f

NAME= 	allum1

SRCS=	main.c \
	fcn1.c \
	fcn2.c

OBJS= 	$(SRCS:.c=.o)

LIB=	./lib/my/libmy.a

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
