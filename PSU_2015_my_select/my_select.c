/*
** my_select.c for my_select.c in /home/Rayan/Systeme Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Dec  1 23:31:12 2015 AKKACHE Kaci
** Last update Sun Dec 13 17:36:30 2015 AKKACHE Kaci
*/

#include <curses.h>
#include <stdlib.h>
#include "./include/my.h"
#include "my_select.h"

int	lenout(t_dbl *l)
{
  t_e	*pelem;
  int	i;
  int	len;

  i = 0;
  len = 0;
  pelem = l->first;
  while (i < l->t)
    {
      if (pelem->select == 1)
	len = len + my_strlen(pelem->val) + 1;
      pelem = pelem->next;
      i = i + 1;
    }
  return (len);
}

char	*enter(t_dbl *l)
{
  t_enter	enter;

  enter.str = malloc(lenout(l));
  enter.i = 0;
  enter.k = 0;
  enter.pelem = l->first;
  while (enter.i < l->t)
    {
      if (enter.pelem->select == 1)
	{
	  enter.j = 0;
	  while (enter.pelem->val[enter.j] != '\0')
	    {
	      enter.str[enter.k] = enter.pelem->val[enter.j];
	      enter.k = enter.k + 1;
	      enter.j = enter.j + 1;
	    }
	  enter.str[enter.k] = ' ';
	  enter.k = enter.k + 1;
	}
      enter.pelem = enter.pelem->next;
      enter.i = enter.i + 1;
    }
  enter.str[enter.k] = '\0';
  return (enter.str);
}

t_sel	if1(t_sel sel, t_dbl *l)
{
  if (sel.key == KEY_DOWN)
    {
      crsol(l, sel.i, 0);
      if (sel.i == l->t)
	sel.i = 0;
      else
	sel.i = sel.i + 1;
      crsol(l, sel.i, 1);
    }
  if (sel.key == KEY_UP)
    {
      crsol(l, sel.i, 0);
      if (sel.i == 0)
	sel.i = l->t;
      else
	sel.i = sel.i - 1;
      crsol(l, sel.i, 1);
    }
  return (sel);
}

t_sel	if2(t_sel sel, t_dbl *l)
{
  if (sel.key == 32)
    {
      select_e(l, sel.i);
      crsol(l, sel.i, 0);
      sel.i = sel.i + 1;
      crsol(l, sel.i, 1);
    }
  if (sel.key == 10)
    {
      sel.r = 1;
      sel.str = enter(l);
    }
  if (sel.key == KEY_BACKSPACE)
    {
      delete(l, sel.i);
      crsol(l, sel.i, 1);
    }
  if (sel.key == 27)
    sel.r = 1;
  return (sel);
}

char	*my_select(t_dbl *l, char **t)
{
  t_sel	sel;

  SCREEN	*win;

  sel.r = 0;
  win = newterm(NULL, stderr, stdin);
  set_term(win);
  keypad(stdscr, TRUE);
  l->first->crson = 1;
  sel.i = 0;
  while (sel.r == 0)
    {
      sel = if1(sel, l);
      sel = if2(sel, l);
      if (sel.r == 0)
	{
	  clear();
	  affnlist(l, t);
	  refresh();
	  sel.key = getch();
	}
    }
  endwin();
  return (sel.str);
}
