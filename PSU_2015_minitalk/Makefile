##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Mon Feb  1 14:35:13 2016 AKKACHE Kaci
##

CC= 	gcc -g3

RM= 	rm -f

NAME= 	./server/server

NAME2= 	./client/client

SRCS=	server.c \

SRCS2=	client.c \

OBJS= 	$(SRCS:.c=.o)

OBJS2= 	$(SRCS2:.c=.o)

LIB=	./lib/my/libmy.a

all:	$(NAME) $(NAME2)


$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

$(NAME2):$(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2) $(LIB)

clean:
	$(RM) $(OBJS) $(OBJS2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: 	fclean all

.PHONY: all clean fclean re
