/*
** infin_opp.c for infin_opp.c in /home/afou_n/rendu/Piscine_C_evalexpr
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Fri Oct 30 14:55:39 2015 Afou Nacerdine
** Last update Tue Nov  3 22:04:04 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

char	*infin_add(char *s1, char *s2)
{
  char	*s1c;
  char	*s2c;
  char	*s3;
  int	n;
  int	size;

  (my_strlen(s1) < my_strlen(s2)) ?
    (size = my_strlen(s2)) : (size = my_strlen(s1));
  s3 = malloc(sizeof(char) * (size + 1));
  s1c = my_revcopy(s1, size);
  s2c = my_revcopy(s2, size);
  if (s1[0] == '-' && s2[0] == '-')
    s3 = infin_doubleneg(s1c,s2c);
  else if ((s1[0] == '-') || (s2[0] == '-'))
    {
      n = checkparams(s1c, s2c);
      (n == 1) ? (s3 = infin_addneg(s1c, s2c)) : (s3 = infin_addneg(s2c, s1c));
      if (((n == 1 && s1[0] == '-') ||
	   (n == 0 && s2[0] == '-')) && (s3[my_strlen(s3) - 1] != '0'))
        s3[my_strlen(s3)] = '-';
    }
  else
    s3 = infin_addpositiv(s1c, s2c);
  s3 = my_revstr(s3);
  return (s3);
}

char	*infin_sub(char *s1, char *s2)
{
  t_list_sub sub;

  (my_strlen(s1) < my_strlen(s2)) ?
    (sub.size = my_strlen(s2)) : (sub.size = my_strlen(s1));
  sub.s3 = malloc(sizeof(char) * (sub.size + 1));
  sub.s1cpy = my_revcopy(s1, sub.size);
  sub.s2cpy = my_revcopy(s2, sub.size);
  sub.n = checkparams(sub.s1cpy, sub.s2cpy);
  if ((s1[0] == '-' && s2[0] == '-') || (s1[0] != '-' && s2[0] != '-'))
    {
      (sub.n == 1) ? (sub.s3 = infin_addneg(sub.s1cpy, sub.s2cpy)) :
	(sub.s3 = infin_addneg(sub.s2cpy , sub.s1cpy));
      if (((sub.n == 1 && s1[0] == '-') || (sub.n == 0 && s2[0] != '-'))
	  && (sub.s3[my_strlen(sub.s3) - 1] != '0'))
        sub.s3[my_strlen(sub.s3)] = '-';
    }
  else if ((s1[0] == '-') || (s2[0] == '-'))
    {
      sub.s3 = infin_addpositiv(sub.s1cpy, sub.s2cpy);
      if ((s1[0] == '-') && (sub.s3[my_strlen(sub.s3) - 1] != '0'))
        sub.s3[my_strlen(sub.s3)] = '-';
    }
    sub.s3 = my_revstr(sub.s3);
  return (sub.s3);
}

char    *infin_mult(char *nb1, char *nb2)
{
  char	*nb1cpy;
  char	*nb2cpy;
  char	*result;
  char	**tab;
  int	size;
  int	n;
  int	strlen;

  size = (my_strlen(nb1) + my_strlen(nb2));
  result = malloc(sizeof(char) * (size + 1));
  tab = malloc(sizeof(char *) * (size + 1));
  nb1cpy = my_revcopy(nb1, size);
  nb2cpy = my_revcopy(nb2, size);
  n =checkparams(nb1cpy , nb2cpy);
  (n == 1) ? (tab = infin_mult1(nb2cpy,nb1cpy, my_strlen(nb2))) :
    (tab = infin_mult1(nb1cpy,nb2cpy, my_strlen(nb1)));
  result = sum(tab, size);
  if ((nb1[0] != '-' && nb2[0] == '-' ) || (nb1[0] == '-' && nb2[0] != '-'))
    (result = infin_sub("0",result));
  return (result);
}

char   *infin_div(char*nb1, char *nb2)
{
  char  *nb1cpy;
  char  *nb2cpy;
  char  *result;

  result = malloc(sizeof(char) * (my_strlen(nb1) + 1));
  nb1cpy = my_copy(nb1);
  nb2cpy = my_copy(nb2);
  result = my_deletez(my_revstr(infin_divcal(nb1cpy,nb2cpy)));
  result = my_revstr(result);
  if ((nb1[0] != '-' && nb2[0] == '-' )|| (nb1[0] == '-' && nb2[0] != '-'))
    (result = infin_sub("0",result));
  return (result);
}

char   *infin_modulo(char*nb1, char *nb2)
{
  char  *nb1cpy;
  char  *nb2cpy;
  char  *result;

  result = malloc(sizeof(char) * (my_strlen(nb1) + 1));
  nb1cpy = my_copy(nb1);
  nb2cpy = my_copy(nb2);
  result = my_deletez(my_revstr(infin_modulocal(nb1cpy,nb2cpy)));
  result = my_revstr(result);
  return (result);
}
