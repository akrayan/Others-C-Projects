/*
** my.h for  in /home/axel/Bureau/lib fonctionnelle
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Mon Feb 15 15:49:23 2016 Axel Proust
** Last update Mon Mar  7 12:19:01 2016 AKKACHE Kaci
*/

#ifndef MY_H_
# define MY_H_

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int			aff_my_put_nbr(va_list ap);
int			my_put_nbr(int nb);
int			aff_my_put_nbr_basep(va_list ap);
int			my_strcmp(const char *s1, const char *s2);
int			my_strncmp(const char *s1, const char *s2, int nb);
char			*my_strdup2(char *str);
char			*my_strdup(char *str);
int			aff_my_put_nbr_base(va_list ap);
int			aff_my_put_nbr_BASE(va_list ap);
int			my_put_nbr_base(int nb);
int			my_put_nbr_BASE(int nb);
int			my_put_nbr_basep(long nb);
int			my_affstr(va_list ap);
int			my_putstr(char *str);
int			aff_convert_oct(va_list ap);
int			aff_convert_bin(va_list ap);
int			my_put_moins(int nb);
int			convert_oct(int nb);
int			convert_bin(int nb);
int			aff_modulo(va_list ap);
int			modulo(int c);
char			*my_revstr(char *str);
int			my_return(int nb);
int			calc(va_list ap);
int			my_show_wordtab(char **tab);
int			count_line(char *str, char sep);
char			**str_to_wordtab(char *str, char sep);
char			*my_strcpy(char *dest, char *src);
int			aff_my_put_nbru(va_list ap);
int			my_put_nbru(unsigned int nb);
int			aff_my_putchar(va_list ap);
int			my_putchar(int c);
int			aff_my_putStr(va_list ap);
int			my_putStr(char *str);
int			my_strlen(char *str);
int			check_char(char c);
void			check_aff(int i, va_list ap);
int			conditions(const char *str, va_list ap, int i);
int			my_printf(const char *str, ...);
int			my_getnbr(char *str);
char			*str_cat(char *dest, char *src);
char			*str_cat2(char *dest, char *src);

#endif /* !MY_H_ */
/* In ./str_to_wordtab.c */
/* In ./str_cat.c */
/* In ./lib/my_put_nbr.c */
int			aff_my_put_nbr(va_list ap);
int			my_put_nbr(int nb);
/* In ./lib/autres.c */
int			aff_my_put_nbr_basep(va_list ap);
/* In ./lib/my_strcmp.c */
int			my_strcmp(const char *s1, const char *s2);
int			my_strncmp(const char *s1, const char *s2, int nb);
/* In ./lib/my_strdup.c */
char			*my_strdup2(char *str);
char			*my_strdup(char *str);
/* In ./lib/my_put_nbrbase.c */
int			aff_my_put_nbr_base(va_list ap);
int			aff_my_put_nbr_BASE(va_list ap);
int			my_put_nbr_base(int nb);
int			my_put_nbr_BASE(int nb);
int			my_put_nbr_basep(long nb);
/* In ./lib/my_putstr.c */
int			my_affstr(va_list ap);
int			my_putstr(char *str);
/* In ./lib/my_put_nbroctal.c */
int			aff_convert_oct(va_list ap);
int			aff_convert_bin(va_list ap);
int			my_put_moins(int nb);
int			convert_oct(int nb);
int			convert_bin(int nb);
/* In ./lib/modulo.c */
int			aff_modulo(va_list ap);
int			modulo(int c);
/* In ./lib/my_revstr.c */
char			*my_revstr(char *str);
/* In ./lib/my_static.c */
int			my_return(int nb);
int			calc(va_list ap);
/* In ./lib/str_to_wordtab.c */
int			my_show_wordtab(char **tab);
int			count_line(char *str, char sep);
char			**str_to_wordtab(char *str, char sep);
/* In ./lib/my_strcpy.c */
char			*my_strcpy(char *dest, char *src);
/* In ./lib/my_put_nbru.c */
int			aff_my_put_nbru(va_list ap);
int			my_put_nbru(unsigned int nb);
/* In ./lib/my_putchar.c */
int			aff_my_putchar(va_list ap);
int			my_putchar(int c);
/* In ./lib/my_putStr.c */
int			aff_my_putStr(va_list ap);
int			my_putStr(char *str);
/* In ./lib/my_strlen.c */
int			my_strlen(char *str);
/* In ./lib/my_printf.c */
int			check_char(char c);
void			check_aff(int i, va_list ap);
int			conditions(const char *str, va_list ap, int i);
int			my_printf(const char *str, ...);
/* In ./lib/my_getnbr.c */
int			my_getnbr(char *str);
/* In ./lib/str_cat.c */
char			*str_cat(char *dest, char *src);
char			*str_cat2(char *dest, char *src);

