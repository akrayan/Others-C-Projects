/*
** fcn.c for fcn.c in /home/Rayan/Colle/CPE_colle_semaine6
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 31 21:51:42 2016 AKKACHE Kaci
** Last update Tue May 31 21:52:24 2016 AKKACHE Kaci
*/

#include "./include/brain.h"

char	*sup(char *pt)
{
  pt += 1;
  return (pt);
}

char	*inf(char *pt)
{
  pt -= 1;
  return (pt);
}

char	*add(char *pt)
{
  *pt += 1;
  return (pt);
}

char	*moin(char *pt)
{
  *pt -= 1;
  return (pt);
}

char	*poin(char *pt)
{
  if (write(1, pt, 1) == - 1)
    return (NULL);
  return (pt);
}
