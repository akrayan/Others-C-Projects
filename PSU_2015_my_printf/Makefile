##
## Makefile for Makefile in /home/Rayan/Systeme Unix/PSU_2015_my_printf
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Sat Nov 14 12:16:14 2015 AKKACHE Kaci
## Last update Sat Nov 14 12:16:25 2015 AKKACHE Kaci
##

OBJ=	./my_put_nbr.c \
	./my_put_nbr_uns.c \
	./my_putstr.c \
	./my_strlen.c \
	./my_putchar.c \
	./convert.c \
	./my_revstr.c \
	./my_printf.c \
	./my_function.c \
	./my_function_2.c \
	./my_function_3.c

RM= 	rm -f

NAME=	libmy.a

COM= 	$(OBJ:.c=.o)

all:	$(NAME)

$(NAME):$(COM)
	ar rc $(NAME) $(COM)
	ranlib $(NAME)
clean:
	$(RM) $(COM)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
