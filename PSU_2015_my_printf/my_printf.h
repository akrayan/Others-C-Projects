/*
** my_printf.h for my_printf.h in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:27:21 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:27:24 2015 AKKACHE Kaci
*/

#include <stdarg.h>

#ifndef LIST_H_
#define LIST_H_
char	*my_revstr(char *str);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);
void	my_put_nbr(int nb);
void	my_put_nbr_uns(unsigned int nb);
int	my_printf(const char *str, ...);
char	*convert(long int nbr, long int base, int maj);
char     *zero(char *str);
void    aff_number(va_list ap);
void    aff_char(va_list ap);
void    aff_string(va_list ap);
void    aff_binary(va_list ap);
void    aff_hexa_min(va_list ap);
void    aff_hexa_maj(va_list ap);
void    aff_octa(va_list ap);
void    aff_not_print(va_list ap);
void    aff_modulo(va_list ap);
void    aff_number_uns(va_list ap);
void    aff_pointer(va_list ap);
void    aff_error(va_list ap);
int     stock(const char *str, int i, va_list ap);
int	compteur;
#endif
