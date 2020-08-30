##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Tue Dec 15 10:39:26 2015 AKKACHE Kaci
##

CC= 	cc

RM= 	rm -f

NAME= 	bsq

SRCS=	main.c \
	bsq.c

OBJS= 	$(SRCS:.c=.o)

LIB=	./libmy.a

CFLAGS=	-W -Wall -ansi -pedantic

all:	$(NAME)


$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
