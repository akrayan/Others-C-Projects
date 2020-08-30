##
## Makefile for Makefile in /home/afou_n/rendu/Piscine_C_J10
## 
## Made by Afou Nacerdine
## Login   <afou_n@epitech.net>
## 
## Started on  Fri Oct  9 10:51:47 2015 Afou Nacerdine
## Last update Tue Nov  3 22:54:59 2015 AKKACHE Kaci
##

CC= 	cc

RM= 	rm -f

NAME= 	calc

SRCS=	eval_expr.c \
	infin_function.c \
	infin_opp.c \
	infin_function_2.c \
	infin_function_3.c \
	infin_function_4.c \
	infin_function_5.c \
	infin_function_6.c \
        infin_function_7.c \
        infin_function_8.c \
        infin_function_9.c \
	infin_function_10.c \
	infin_function_11.c \
	add_space.c \
	convert_base_to_nb.c \
	syntax_error.c \
	main.c

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
