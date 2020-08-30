##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Sun Dec 13 16:50:48 2015 AKKACHE Kaci
##

CC= 	cc

RM= 	rm -f

NAME= 	my_select

SRCS=	main.c \
	my_select.c \
	my_function.c \
	affichage.c \
	my_list.c

OBJS= 	$(SRCS:.c=.o)

LIB=	./lib/my/libmy.a -lncurses

all:	$(NAME)


$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
