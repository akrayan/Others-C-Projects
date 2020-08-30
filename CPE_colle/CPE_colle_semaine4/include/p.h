/*
** poke.h for poke.h in /home/Rayan/Colle/CPE_colle_semaine4
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 17 18:16:19 2016 AKKACHE Kaci
** Last update Tue May 17 19:00:51 2016 AKKACHE Kaci
*/

#ifndef		POKE_H
#define		POKE_H

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	<time.h>

typedef struct	s_poke
{
  char		*name;
  int		atk;
  int		def;
  int		vie;
  int		vit;
}		t_poke

typedef struct	s_l
{
  struct s_l	*next;
  struct s_l	*last;
  t_poke	p;
}		t_l;


t_l		*add_elem(t_l *l, t_poke poke);
void		my_putchar(char c);
int		my_putstr(char *str);
int		my_strlen(char *str);

#endif
