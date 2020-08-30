/*
** my_select.h for my_select.h in /home/Rayan/Systeme_Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 16:42:33 2015 AKKACHE Kaci
** Last update Sun Dec 13 17:25:17 2015 AKKACHE Kaci
*/

#ifndef MY_SELECT_H_
# define MY_SELECT

typedef struct s_e
{
  int		select;
  int		crson;
  char		*val;

  struct s_e	*prev;
  struct s_e	*next;
}		t_e;

typedef struct s_dbl
{
  int		t;

  t_e		*first;
  t_e		*last;
}		t_dbl;

typedef struct s_sel
{
  char	*str;
  int	key;
  int	r;
  int	i;
}		t_sel;

typedef struct s_enter
{
  t_e   *pelem;
  char	*str;
  int	i;
  int	j;
  int	k;
}		t_enter;

typedef struct s_aff
{
  t_e	*pelem;
  int	li;
  int	n;
  int	i;
}		t_aff;

int	lenmax(char **t);
void	Init(t_dbl *l);
void	PushBack(t_dbl *l, char *val, int crson, int select);
int	affnlist(t_dbl *l, char **t);
char	*PopFront(t_dbl *l);
t_dbl	*ra(t_dbl *list);
t_dbl	*select_e(t_dbl *l, int indx);
t_dbl	*crsol(t_dbl *l, int indx, int b);
t_dbl	*delete(t_dbl *l, int indx);

#endif
