##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Sun Nov 22 15:04:16 2015 AKKACHE Kaci
##

CC= 	cc

RM= 	rm -f

NAME= 	push_swap

SRCS=	main.c      \
	push_swap.c \
	my_list2.c  \
	my_function.c

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
