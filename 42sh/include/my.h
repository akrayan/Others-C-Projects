/*
** my.h for my.h in /home/afou_n/Github/Piscine/Piscine_C_J09
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Tue Dec 29 13:56:33 2015 Afou Nacerdine
** Last update Tue Mar 29 17:07:00 2016 AKKACHE Kaci
*/

#ifndef MY_H_
# define MY_H_

#ifndef READ_SIZE
# define READ_SIZE (10)
#endif /* !READ_SIZE */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_get_nl
{
  char		*result;
  int		i;
  int		ret;
}		t_get_nl;

/* In ./my_strncpy.c */
char			*my_strncpy(char *dest, char *src, int n);
/* In ./my_epure_str.c */
char			*my_epure_str(char *str);
/* In ./my_showmem.c */
int			my_showmem(char *str, int size);
/* In ./my_copy_wordtab.c */
char			**my_copy_wordtab(char **tab);
/* In ./my_tablen.c */
int			my_tablen(char **tab);
/* In ./my_str_islower.c */
int			my_str_islower(char *str);
/* In ./my_str_isnum.c */
int			is_num(char c);
int			my_str_isnum(char *str);
/* In ./my_strcat.c */
char			*my_strcat(char *dest, char *src);
/* In ./my_is_prime.c */
int			my_is_prime(int nb);
/* In ./my_str_isalpha.c */
int			is_alpha(char c);
int			my_str_isalpha(char *str);
/* In ./my_putchar.c */
void			my_putchar(char c);
int			compteur(int nb);
void			aff_n();
/* In ./get_next_line.c */
int			my_check_end_line(char *str);
char			*my_edit_line(char *str);
char			*my_rest_read(char *str);
char			*my_twostr(char *result, char *buffer);
char			*get_next_line(const int fd);
/* In ./my_show_wordtab.c */
int			my_show_wordtab(char **tab);
/* In ./my_putstr.c */
int			my_putstr(char *str);
/* In ./my_power_rec.c */
int			my_power_rec(int nb, int power);
/* In ./my_strcmp.c */
int			my_strcmp(char *s1, char *s2);
/* In ./my_swap.c */
int			my_swap(int *a, int *b);
/* In ./my_getnbr_base.c */
int			init(char *base, int *nbr, int *j, int *i);
int			check_neg(char *s);
int			check_base(char *base, int n);
int			my_getnbr_base(char *str, char *base);
/* In ./my_strstr.c */
char			*my_strstr(char *str, char *to_find);
/* In ./my_isneg.c */
int			my_isneg(int n);
/* In ./my_strlowcase.c */
int			is_upper(char c);
char			*my_strlowcase(char *str);
/* In ./my_strlen.c */
int			my_strnlen(char *str, char c);
int			my_strlen(char *str);
/* In ./sum_params.c */
char			*sum_params(int ac, char **av);
/* In ./my_revstr.c */
char			*my_revstr(char *str);
/* In ./my_putnbr_base.c */
int			my_putnbr_base(int nbr, char *base);
/* In ./my_showstr.c */
int			my_showstr(char *str);
/* In ./my_strupcase.c */
int			is_lower(char c);
char			*my_strupcase(char *str);
/* In ./my_getnbr.c */
int			is_nbr(char c);
int			is_add_sub(char c);
int			my_getnbr(char *str);
/* In ./my_find_prime_sup.c */
int			my_find_prime_sup(int nb);
/* In ./my_strcpy.c */
char			*my_strcpy(char *dest, char *src);
/* In ./my_square_root.c */
int			my_square_root(int nb);
/* In ./my_strncat.c */
char			*my_strncat(char *dest, char *src, int nb);
/* In ./my_str_isupper.c */
int			my_str_isupper(char *str);
/* In ./my_str_to_wordtab.c */
int			my_wordlen(char *str);
char			**my_str_to_wordtab(char *str);
/* In ./my_strcapitalize.c */
char			*my_strcapitalize(char *str);
/* In ./my_strdup.c */
char			*my_strdup(char *str);
/* In ./my_sort_int_tab.c */
void			swap(int *tab, int index1, int index2);
void			my_sort_int_tab(int *tab, int size);
/* In ./my_strncmp.c */
int			my_strncmp(char *s1, char *s2, int n);
/* In ./my_put_nbr.c */
int			my_put_nbr(int nb);
/* In ./convert_base.c */
int			my_strbase(char *nbr, char *base_from, char *base_to);
char			*convert_base(char *nbr, char *base_from, char *base_to);
/* In ./my_str_isprintable.c */
int			is_printable(char c);
int			my_str_isprintable(char *str);
/* In ./my_printf/pf_putstr.c */
void			pf_putstr(char *str);
/* In ./my_printf/pf_strlen.c */
int			pf_strlen(char *str);
/* In ./my_printf/pf_putnbr_base.c */
void			pf_putnbr_base(unsigned int nbr, char *base);
/* In ./my_printf/pf_flag_next_next.c */
void			flag_count(va_list ap);
void			flag_notprint(va_list ap);
/* In ./my_printf/pf_flag_next.c */
void			flag_putmodulo(va_list ap);
void			flag_hexa_lower(va_list ap);
void			flag_hexa_upper(va_list ap);
void			flag_octal(va_list ap);
void			flag_pointer(va_list ap);
/* In ./my_printf/pf_putchar.c */
void			pf_putchar(char c);
/* In ./my_printf/my_count.c */
int			my_count_n(int count);
/* In ./my_printf/pf_put_nbr.c */
void			pf_put_nbr(int nb);
/* In ./my_printf/my_printf.c */
int			pf_check_after_modulo(const char *format, int i, va_list ap);
int			my_printf(const char *format, ...);
/* In ./my_printf/pf_flag.c */
void			flag_put_nbr(va_list ap);
void			flag_putchar(va_list ap);
void			flag_putstr(va_list ap);
void			flag_binary(va_list ap);
void			flag_put_nbr_uns(va_list ap);
/* In ./my_printf/pf_put_nbr_uns.c */
void			pf_put_nbr_uns(unsigned int nb);
/* In ./my_printf/pf_check_flag.c */
int			pf_ignore_char(const char *format, int i);
int			pf_count_flag(char c);
void			pf_tab_flag(int i, va_list ap);

#endif /* !MY_H_ */
