##
## Makefile for  in /home/axel/rendu/PSU_2015_my_select
## 
## Made by proust axel
## Login   <proust_c@epitech.net>
## 
## Started on  Tue Dec  1 11:03:40 2015 proust axel
## Last update Wed Mar 23 06:37:59 2016 AKKACHE Kaci
##

RM		= rm -f

NAME		= tetris

SRC		= str_to_wordtab.c	\
		  str_cat.c		\
		  tetris.c		\
		  read_tetri.c		\
		  read_tetri2.c		\
		  check.c		\
		  get_tab.c		\
		  debug/option2.c       \
		  debug/option.c        \
		  debug/option3.c       \
		  debug/gestion_av.c    \
		  debug/canon.c         \
		  my_get_nbr.c          \
		  debug/option4.c       \
		  main.c                \
		  tab.c

OBJS		= $(SRC:.c=.o)

CFLAGS		= -g3 -lm

all:		$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS) libmy.a -lncurses -lm

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

