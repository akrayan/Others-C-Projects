/*
** my_ls.h for my_ls.h in /home/Rayan/Systeme Unix/PSU_2015_my_ls
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Nov 26 04:17:59 2015 AKKACHE Kaci
** Last update Sun Nov 29 20:40:09 2015 AKKACHE Kaci
*/

#ifndef MY_LS_H_
# define MY_LS_

typedef struct s_lf
{
  char          *name;
  int           t;
  int		index;

  struct s_lf    *suiv;
  struct s_lf    *first;
  struct s_lf    *last;
}               t_lf;

int     my_ls(char *dir);
t_lf	*add_elemv(t_lf *list, char *name);
t_lf	*add_elemf(t_lf *list, char *name, int id);
t_lf	*sup_elemf(t_lf *list);
t_lf	*sup_elemd(t_lf *list);

#endif
