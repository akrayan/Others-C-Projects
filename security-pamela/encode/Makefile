##
## Makefile for Makefile in /home/billel/encode/bilbil
## 
## Made by BIllel
## Login   <billel.mouhoub@epitech.eu>
## 
## Started on  Sat Nov 25 21:45:18 2017 BIllel
## Last update Sun Nov 26 23:49:16 2017 BIllel
##

CC		=	gcc -g3

RM		=	rm -f

NAME		=	encode

NAME2		=	decode

SRCS		=	src/encode/main.c \
			src/encode/chained_list_gestion.c \
			src/encode/directory_get_names.c \
			src/encode/create_encoded_file.c \
			src/encode/crypto.c

SRCS2		=	src/decode/main.c \
			src/decode/chained_list_gestion.c \
			src/decode/directory_get_names.c \
			src/decode/create_encoded_file.c \
			src/decode/crypto.c

OBJS		=	$(SRCS:.c=.o)

OBJS2		=	$(SRCS2:.c=.o)

CFLAGS		=	-I./include

all:			$(NAME) $(NAME2)

$(NAME):		$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lcrypto

$(NAME2):		$(OBJS2)
			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2) -lcrypto

clean:
			$(RM) $(OBJS) $(OBJS2)

fclean:			clean
			$(RM) $(NAME) $(NAME2)

re:			fclean all
