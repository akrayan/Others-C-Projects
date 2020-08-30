/*
** brain.h for  in /home/vella_c/CPE_colle_semaine6
** 
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
** 
** Started on  Tue May 31 18:18:06 2016 VELLA CYRIL
** Last update Tue May 31 21:50:28 2016 AKKACHE Kaci
*/
#ifndef		BRAIN_H_
# define	BRAIN_H_

# include	<stdlib.h>
# include	<stdio.h>
# include	<sys/stat.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>

int		s_len(char *str);
char		*s_cat(char *str, char *str2);
char		*r_all(char *f);
char		*init_ptr();
char		*sup(char *pt);
char		*inf(char *pt);
char		*add(char *pt);
char		*moin(char *pt);
char		*poin(char *pt);
char		*guil(char *pt);
int		c_par(char *s, char c);

typedef struct	s_s
{
  int		i;
  int		c;
  char		*s;
  char		*par;
  char		*pt;
  char		*(*t[6])(char *);
}		t_s;

# endif
