##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Thu Nov 26 10:09:42 2015 AKKACHE Kaci
##

CC= 	cc

RM= 	rm -f

NAME= 	my_ls

SRCS=	main.c \
	my_ls.c \
	my_list2.c

OBJS= 	$(SRCS:.c=.o)

LIB= 	./lib/my/libmy.a

all:	$(NAME)


$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
