/*
** option3.c for  in /home/axel/rendu/PSU/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Tue Mar  8 13:39:35 2016 Axel Proust
** Last update Sun Mar 20 22:32:02 2016 AKKACHE Kaci
*/

#include "../tetris.h"

void		change_oa(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == 27)
	my_putstr("^E");
      else if (str[i] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[i]);
    }
}

int             key_quit(t_opt *opt)
{
  static int	i;

  if (i != 0)
    return (-1);
  else
    opt->quit = my_strdup(opt->arg);
  i++;
}

int             key_pause(t_opt *opt)
{
  static int	i;

  if (i != 0)
    return (-1);
  else
    opt->pause = my_strdup(opt->arg);
  i++;
}

int             hide_next(t_opt *opt)
{
  static int	i;

  if (i != 0)
    return (-1);
  opt->next = my_strdup("No");
  i++;
}

int		debug2(t_opt *opt)
{
  int           i;
  t_t           tab;
  t_te          te;

  i = 0;
  read_tet(&te);
  tab = get_tab(te, tab);
  printf("Tetriminos : %d\n", tab.g[0].len);
  while (i < tab.g[0].len)
    {
      if (tab.g[i].i == 1)
	{
	  my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n", tab.g[i].n, tab.g[i].cl, tab.g[i].l, tab.g[i].c);
	  my_show_wordtab(tab.g[i].t);
	}
      else
	printf("Tetriminos : Name %s : Error\n", tab.g[i].n);
      i++;
    }
  printf("Press a key to start Tetris\n");
}

int             debug(t_opt *opt)
{
  t_te *te;
  static int	n;

  if (n != 0)
    return (-1);
  n++;
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : ");
  change_oa(opt->left);
  my_printf("\nKey Right : ");
  change_oa(opt->right);
  my_printf("\nKey Turn : ");
  change_oa(opt->turn);
  my_printf("\nKey Drop : ");
  change_oa(opt->drop);
  my_printf("\nKey Quit : ");
  change_oa(opt->quit);
  my_printf("\nKey Pause : ");
  change_oa(opt->pause);
  my_printf("\nNext : %s\nLevel : %d\nSize : %d*%d\n", opt->next, opt->level, opt->map_h, opt->map_w);
  debug2(opt);
}

int             map_size(t_opt *opt)
{
  int		i;
  char		*stock;
  char		*stock2;
  int		j;

  i = -1;
  j = 0;
  if ((stock = malloc(sizeof(char) * (10))) == NULL)
    return (-1);
  while (opt->arg[++i] != ',')
      stock[i] = opt->arg[i];
  stock[i + 1] = '\0';
  i++;
  stock2 = my_strdup(opt->arg + i);
  if ((opt->map_w = my_get_nbr(stock)) == -1)
    return (-1);
  if ((opt->map_h = my_get_nbr(stock2)) == -1)
    return (-1);
}
