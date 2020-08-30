SRC=			./main.c \
			./my_putall.c \

OBJ=			 $(SRC:.c=.o)

NAME=			 rev_wstr

CFLAGS=			-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
