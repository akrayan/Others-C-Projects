/*
** allum.h for alllum.h in /home/Rayan/Prog_Elem2/CPE_2015_Allum1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Feb 20 21:36:21 2016 AKKACHE Kaci
** Last update Sun Feb 21 09:32:33 2016 AKKACHE Kaci
*/

#ifndef ALLUM_H
#define ALLUM_H

#include <stdlib.h>
#include <time.h>
#include "./my.h"

typedef struct	s_index
{
  int	i;
  int	n;
}		t_index;

typedef struct	s_tab_var
{
  char	**t;
  char	**wt;
  int	i;
  int	j;
}		t_tab_var;

char		*new_copy(char *str);
char		*read_st(const int fd);
char		**init_tab();
int		nb_a(char *t);
char		**r_allum(char **t, int i, int nb);
int		snb_a(char **t);
char		check_s(char *s);
t_index		matche(char **t, char *s, t_index id);
t_index		line(char **t, char *s, t_index id, int l);
char		**p_turn(char **t, int l);
char		**c_turn(char **t, int l);
int		check_win(char **t, char tour);
void		allum(int l, int al);

#endif
