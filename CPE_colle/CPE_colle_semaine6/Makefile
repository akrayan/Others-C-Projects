##
## Makefile for  in /home/vella_c/CPE_colle_semaine6
## 
## Made by VELLA CYRIL
## Login   <Cyril@epitech.net>
## 
## Started on  Tue May 31 18:09:49 2016 VELLA CYRIL
## Last update Tue May 31 21:52:58 2016 AKKACHE Kaci
##

CC	= cc

RM	= rm -f

NAME	= brainflff

SRCS	= main.c	\
	  my_strcat.c	\
	  fcn.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
