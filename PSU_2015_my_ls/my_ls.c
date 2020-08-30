/*
** my_ls.c for my_ls.c in /home/Rayan/Systeme Unix/PSU_2015_my_ls
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Nov 25 23:51:31 2015 AKKACHE Kaci
** Last update Sun Nov 29 21:33:43 2015 AKKACHE Kaci
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "./my_ls.h"
#include "./include/my.h"

t_lf	*my_getlist(char *dir, t_lf *list)
{
  int	i;
  DIR	*d;
  struct dirent	*entry;

  i = 0;
  if ((d = opendir(dir)) == NULL)
    {
      my_putstr("ERROR\n");
      exit(-1);
    }
  list = add_elemf(list, "fake", -1);
  while ((entry = readdir(d)) != NULL)
    {
      if (entry->d_name[0] != '.')
	list = add_elemf(list, entry->d_name, i);
      i = i + 1;
    }
  list = sup_elemd(list);
  return (list);
}

int	my_afflist(t_lf *list)
{
  t_lf	*p;

  if (list == NULL)
    {
      my_putstr("NACER TU DEUHR VOILA PK SA SEGFAULT");
      return (-1);
    }
  p = list->first;
  while (p != NULL)
    {
      my_putstr(p->name);
      p = p->suiv;
      if (p != NULL)
	my_putchar(' ');
    }
  my_putchar('\n');
}

int	my_ls(char *dir)
{
  t_lf	*list;

  list = NULL;
  list = my_getlist(dir, list);
  my_afflist(list);
}
