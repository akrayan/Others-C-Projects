/*
** poke.h for poke.h in /home/Rayan/Colle/CPE_colle_semaine4
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 17 18:58:12 2016 AKKACHE Kaci
** Last update Tue May 17 21:50:01 2016 VELLA CYRIL
*/


#ifndef		POKE_H
 #define       	POKE_H

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<dirent.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<time.h>

typedef struct	s_fight
{
  int		a;
  int		b;
  int		l;
}		t_fight;

typedef struct	s_poke
{
  char		*name;
  int		atk;
  int		def;
  int		vie;
  int		vit;
}		t_poke;

typedef struct	s_l
{
  struct s_l	*next;
  struct s_l	*last;
  t_poke	p;
}		t_l;

int		list_len(t_l *l);
t_l		*add_elem(t_l *l, t_poke poke);
char		my_putchar(char c);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_putnbr(int nb);
char		*s_c(char *s1, char *s2);
char		*s_dup(char *s);
char		*read_all();
int		aff1(t_poke p1, t_poke p2, t_fight f);
int		aff2(t_poke p1, t_poke p2, t_fight f);
void		fight(t_poke p1, t_poke p2);
int		live(t_poke p1, t_poke p2);

#endif
