##
## Makefile for Makefile in /home/Rayan/Systeme Unix/PSU_2015_my_printf_bootstrap
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Fri Nov  6 15:03:28 2015 AKKACHE Kaci
## Last update Fri Nov  6 15:03:35 2015 AKKACHE Kaci
##

M=     rm -f

SRCS=   sum_stdarg.c \
        disp_stdarg.c \
        my_putchar.c \
        my_put_nbr.c \
        my_putstr.c \
        my_strlen.c

OBJS=   $(SRCS:.c=.o)

LIB=    libmy.a

all:    $(LIB)


$(LIB):$(OBJS)
        ar rc $(LIB) $(OBJS)
        ranlib $(LIB)

clean:
        $(RM) $(OBJS)

fclean: clean
        $(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
