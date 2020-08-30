##
## Makefile for Makefile in /home/rayan/Memory/PSU_2016_nmobjdump
## 
## Made by Rayan
## Login   <raihane.akkache@epitech.net>
## 
## Started on  Sun Feb 26 11:30:35 2017 Rayan
## Last update Sun Feb 26 17:31:41 2017 Rayan
##

RM		= rm -f

NM		= my_nm

OBJDUMP		= my_objdump

SRCS1		=  mynm/my_nm.c \

SRCS2		 = myod/my_objdump.c \

# CFLAGS		= -W -Wall -Werror -Wextra

OBJS_NM		= $(SRCS1:.c=.o)

OBJS_OBJDUMP	= $(SRCS2:.c=.o)

all:		$(NM) $(OBJDUMP)

nm:		$(NM)

objdump:	$(OBJDUMP)

$(NM): 		$(OBJS_NM)
		gcc -o $(NM) $(OBJS_NM)

$(OBJDUMP): 	$(OBJS_OBJDUMP)
		gcc -o $(OBJDUMP) $(OBJS_OBJDUMP)

clean:
		$(RM) $(OBJS_OBJDUMP) $(OBJS_NM)

fclean: 	clean
		$(RM) $(NM) $(OBJDUMP)

re:		fclean all

.PHONY:		all clean fclean re
