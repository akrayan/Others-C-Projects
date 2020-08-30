/*
** maze.h for maze.h in /home/Rayan/CPE_colle_semaine1/include
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 26 18:33:31 2016 AKKACHE Kaci
<<<<<<< HEAD
** Last update Tue Apr 26 21:54:43 2016 AKKACHE Kaci
=======
** Last update Tue Apr 26 19:21:30 2016 VELLA CYRIL
>>>>>>> a18b1103cdbef7b88d8eb3565dcc4d7ca6d8f358
*/

#ifndef MAZE_H
 #define MAZE_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_h
{
  struct s_h	*next;
  char		p;
}		t_h;

typedef struct	s_par
{
  char		w;
  char		s;
  char		e;
  char		r;
  char		o;
}		t_par;

t_h	*add_elem(char v, t_h *h);
t_h	*sup_elem(t_h *h);
void	my_putchar(char c);
int	my_putstr(char *str);
int	slen(char *str);
char	*scat(char *str, char *str1);
char	*read_all(char *s, char *f);
char	*sdup(char *str);
char	**stw(char *s, char c);

#endif /* !MAZE_H */
