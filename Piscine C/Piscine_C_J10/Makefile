##
## Makefile for Makefile in /home/Rayan/Piscine_C_J10
## 
## Made by AKKACHE Kaci
## Login   <Rayan@epitech.net>
## 
## Started on  Mon Oct 12 20:35:22 2015 AKKACHE Kaci
## Last update Mon Oct 12 20:35:47 2015 AKKACHE Kaci
##

OBJ= my_isneg.c my_showmem.c my_strcapitalize.c  my_str_isalpha.c my_str_isupper.c  my_strncat.c  my_strupcase.c my_is_prime.c my_put_nbr.c my_showstr.c my_strcat.c my_str_islower.c my_strl\
cat.c my_strncmp.c my_swap.c my_find_prime_sup.c my_power_rec.c my_putstr.c my_sort_int_tab.c my_strcmp.c my_str_isnum.c my_strlen.c my_strncpy.c my_getnbr.c my_putchar.c my_revstr.c my_squ\
are_root.c my_strcpy.c my_str_isprintable.c my_strlowcase.c my_strstr.c

COM= $(OBJ:.c=.o)

all:    $(COM)
        ar rc libmy.a *.o
        ranlib libmy.a
        cp libmy.a ../
        cp my.h ../../include/
clean:
        rm $(COM)
fclean:         clean
