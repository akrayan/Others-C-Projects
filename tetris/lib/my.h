/*
** my.h for  in /home/axel/Bureau/lib fonctionnelle
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Mon Feb 15 15:49:23 2016 Axel Proust
** Last update Mon Feb 15 15:53:49 2016 Axel Proust
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

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
