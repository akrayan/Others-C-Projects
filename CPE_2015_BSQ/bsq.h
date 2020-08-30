/*
** bsq.h for bsq.h in /home/Rayan/Prog_Elem/CPE_2015_BSQ
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 21:58:17 2015 AKKACHE Kaci
** Last update Tue Dec 15 11:35:25 2015 AKKACHE Kaci
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_sqr
{
  int		x;
  int		y;
  int		t;
}               t_sqr;

typedef struct	s_c
{
  int		n;
  int		r;
  int		i;
  int		j;
  t_sqr		sqr;
}		t_c;

t_c     function(t_c c, char **t);
t_sqr	check_t(int i, int j, char **t);
t_sqr	search(char **t);
int	bsq(char **t);
int	nb_l(char *str);
char	**tab_for_bsq(char *str);
int	open_file(char *filepath);
char	*my_read_inf(char *filepath);

#endif
