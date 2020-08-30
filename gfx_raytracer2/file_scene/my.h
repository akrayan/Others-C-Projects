/*
** my.h for my in /home/nasrat_v/rendu/Piscine_C_J09/ex_02
**
** Made by valentin nasraty
** Login   <nasrat_v@epitech.net>
**
** Started on  Thu Oct  8 15:00:38 2015 valentin nasraty
** Last update Tue Apr 26 16:50:23 2016 
*/

#ifndef	MY_H_
# define MY_H_

#  define READ_SIZE (2)

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct  s_printf
{
  int           a;
  int           x;
  char          *pointeur;
  va_list       ap;
}               t_printf;

typedef struct	s_line
{
  char		*buffer1;
  char		*buffer2;
  char		*str;
  int		count;
}		t_line;

int		put_float(float nb);
void		get_float(va_list ap);
void		my_puterror(char c);
void		my_putchar(int c);
void		my_put_nbr(int nb);
void		my_putstr(char *str);
void		my_strerror(char *str);
void		binaire(int n);
void		hexadecimal(int nb);
void		my_put_unsigned_nbr(unsigned int nb);
void		big_hexadecimal(int nb);
void		not_print(char *str);
void		octal_bis(int nb);
void		my_zero(char *str);
void		chicken(long nb);
void		my_sort_in_tab(int *tab, int size);
void		my_show_wordtab(char **tab);
int		my_square_root(int nb);
int		my_find_prime_sup(int nb);
int		my_getnbr(char *str);
int		my_isneg(int n);
int		my_is_prime(int nb);
int		my_power_rec(int nb, int power);
int		my_strlen(char *str);
int		my_strlen2(char *str, int option);
int		check_aff(int n, ...);
int		base_l(int nb, int base);
int		nuggets(long nb, long base);
int		my_ret(char *str);
int		my_showmem(char *str, int size);
int		my_showstr(char *str);
int		my_strlen(char *str);
int		my_swap(int *a, int *b);
int		my_str_isalpha(char *str);
int		my_str_islower(char *str);
int		my_str_isnum(char *str);
int		my_strncmp(char *s1, char *s2, int n);
int		my_str_isprintable(char *str);
int		my_str_isupper(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_printf(char const *str, ...);
char		burger(int n);
char		*my_strlowcase(char *str);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strncat(char *dest, char *src, int nb);
char		*my_strstr(char *str, char *to_find);
char		*my_strupcase(char *str);
char		*my_strcapitalize(char *str);
char		*my_strcat(char *dest, char *src);
char		*my_revstr(char *str);
char		*my_strcpy(char *dest, char *src);
char		*octal(int nb);
char		*check_fd(const int op, int n, int count, char *retour);
char		*get_next_line(const int fd);
char		*read_inf(char *buffer, char *buffer2);
char		*infin_read(const int op);

#endif /* !MY_H_ */
