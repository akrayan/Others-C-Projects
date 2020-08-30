##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Fri Jun  3 23:45:32 2016 AKKACHE Kaci
##

CC= 	gcc -g3

RM= 	rm -f

NAME= 	mysh

SRCS=	main.c		\
	cmd_tab.c	\
	clean.c		\
	s_t_w.c		\
	path.c		\
	list.c		\
	env.c		\
	cmd1.c		\
	cmd2.c		\
	cmd3.c		\
	f1.c		\
	f2.c		\
	f3.c		\
	f4.c		\
	my_term.c	\
	my_prompt.c

OBJS= 	$(SRCS:.c=.o)

LIB=	./lib/libmy.a

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
