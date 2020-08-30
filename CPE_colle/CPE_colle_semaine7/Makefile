##
## Makefile for  in /home/vella_c/CPE_colle_semaine7
## 
## Made by VELLA CYRIL
## Login   <Cyril@epitech.net>
## 
## Started on  Mon Jun  6 18:03:55 2016 VELLA CYRIL
## Last update Mon Jun  6 21:20:12 2016 AKKACHE Kaci
##

CC	=	cc

RM	=	rm -f

NAME	=	decrypt

NAME2	=	encrypt

SRCS	=	decrypt.c	\
		str.c		\

SRCS2	=	crypt.c	\
		crypt2.c	\
		str.c	\

OBJS	=	$(SRCS:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra -W

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(NAME2): $(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2)

clean:
	$(RM) $(OBJS) $(OBJS2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
