/*
** affichage.c for affichage.c in /home/Rayan/Systeme Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 14:33:19 2015 AKKACHE Kaci
** Last update Sun Dec 13 20:33:03 2015 AKKACHE Kaci
*/

#include <curses.h>
#include <stdlib.h>
#include "./include/my.h"
#include "my_select.h"

t_aff	affi(t_aff aff, t_dbl *l , char **t)
{
  aff.li = 0;
  while (aff.li < (LINES) && aff.i < l->t)
    {
      if (aff.pelem->select == 1 || aff.pelem->crson == 1)
	{
	  if (aff.pelem->select == 1)
	    attron(A_REVERSE);
	  if (aff.pelem->crson == 1)
	    attron(A_UNDERLINE);
	  mvprintw(aff.li, (aff.n * lenmax(t) + aff.n), aff.pelem->val);
	  attroff(A_UNDERLINE);
	  attroff(A_REVERSE);
	}
      else
	mvprintw(aff.li, (aff.n * lenmax(t)) + aff.n, aff.pelem->val);
      aff.pelem = aff.pelem->next;
      aff.i = aff.i + 1;
      aff.li = aff.li + 1;
    }
  return (aff);
}

int	affnlist(t_dbl *l, char **t)
{
  t_aff aff;
  int	nb;
  int	nb2;

  nb = COLS / lenmax(t);
  nb2 = (l->t / LINES) + 1;
  aff.n = 0;
  aff.i = 0;
  aff.pelem = l->first;
  curs_set(0);
  while (aff.n < nb2)
    {
      if ((aff.n + 1) * lenmax(t) + aff.n < COLS)
	aff = affi(aff, l, t);
      else
	{
	  clear();
	  refresh();
	  printw("Dimension trop petite veuillez redimensioner");
	}
      aff.n = aff.n + 1;
    }
}
