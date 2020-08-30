/*
** push_swap.h for push_swap.h in /home/Rayan/Prog Elem/CPE_2015_Pushswap
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Nov 16 18:15:06 2015 AKKACHE Kaci
** Last update Sun Nov 22 16:36:38 2015 AKKACHE Kaci
*/

#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_

typedef struct s_l
{
  int		nb;
  int		t;

  struct s_l	*suiv;
  struct s_l	*first;
  struct s_l	*last;
}		t_l;

typedef struct s_c
{
  t_l		*la;
  t_l		*lb;
}		t_c;

t_l	*push_swap5(t_c *ll);
t_l	*add_elemv(t_l *list, int nb);
t_l	*add_elemd(t_l *list, int nb);
t_l	*add_elemf(t_l *list, int nb);
t_l	*sup_elemd(t_l *list);
t_l	*sup_elemf(t_l *list);
t_l	*my_getlist(t_l *list, char **param);
t_l	*putlb(t_c *ll);
t_l	*sa(t_l *list);
t_l	*ra(t_l *list);
t_l	*rra(t_l *list);
t_c	*pa(t_c *ll);
t_c	*pb(t_c *ll);
void	*aff_list(t_l *list);
int	check_list(t_l *list);
int	check_idx(t_l *list);

#endif
