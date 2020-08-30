##
## Makefile for Makefile in /home/Rayan/Info/noise_2020
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Nov  9 17:51:20 2015 AKKACHE Kaci
## Last update Sun Dec  6 19:15:45 2015 AKKACHE Kaci
##

CC= 	cc

RM= 	rm -f

NAME= 	fdf

SRCS=	main.c \
	flammes.c \
	flammes2.c \
	plasma.c \
	my_background.c \
	my_set_pixel.c

OBJS= 	$(SRCS:.c=.o)

LIB= 	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -llapin -L/usr/local/lib ./lib/my/libmy.a


all:	$(NAME)


$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
