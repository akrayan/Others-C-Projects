/*
** option.c for  in /home/axel/rendu/PSU/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Mon Mar  7 10:59:25 2016 Axel Proust
** Last update Sun Mar 20 19:56:58 2016 Axel Proust
*/

#include "../tetris.h"
#include <stdlib.h>

void		check_opt(t_opt *opt)
{
  if ((opt->tab_opt = malloc(sizeof(char *) * 21)) == NULL)
    return (NULL);
  opt->tab_opt[0] = my_strdup("--help");
  opt->tab_opt[1] = my_strdup("-l");
  opt->tab_opt[2] = my_strdup("-kl");
  opt->tab_opt[3] = my_strdup("-kr");
  opt->tab_opt[4] = my_strdup("-kt");
  opt->tab_opt[5] = my_strdup("-kd");
  opt->tab_opt[6] = my_strdup("-kq");
  opt->tab_opt[7] = my_strdup("-kp");
  opt->tab_opt[8] = my_strdup("-w");
  opt->tab_opt[9] = my_strdup("-d");
  opt->tab_opt[10] = my_strdup("--level=");
  opt->tab_opt[11] = my_strdup("--key-left=");
  opt->tab_opt[12] = my_strdup("--key-right=");
  opt->tab_opt[13] = my_strdup("--key-turn=");
  opt->tab_opt[14] = my_strdup("--key-drop=");
  opt->tab_opt[15] = my_strdup("--key-quit=");
  opt->tab_opt[16] = my_strdup("--key-pause=");
  opt->tab_opt[17] = my_strdup("--without-next=");
  opt->tab_opt[18] = my_strdup("--debug=");
  opt->tab_opt[19] = my_strdup("--map-size=");
  opt->tab_opt[20] = NULL;
}

int		function_op(t_opt *opt)
{
  char		**tab;
  int		i;
  char		*commande;

  i = -1;
  clear_commande(opt);
  check_opt(opt);
  while (opt->tab_opt[++i])
    {
      if (strcmp(opt->tab_opt[i], opt->commande) == 0)
	return (i);
    }
  return (-1);
}

int		point_opt(t_opt *opt)
{
  int		(*check[11])(t_opt *);
  int		nb;

  if ((nb = function_op(opt)) == -1)
    return (-1);
  if (nb > 9 && nb != 19)
    nb = nb -9;
  else if (nb == 19)
    nb = 10;
  check[0] = &show_help;
  check[1] = &start_level;
  check[2] = &my_key_left;
  check[3] = &my_key_right;
  check[4] = &key_turn;
  check[5] = &key_drop;
  check[6] = &key_quit;
  check[7] = &key_pause;
  check[8] = &hide_next;
  check[9] = &debug;
  check[10] = &map_size;
  (*check[nb])(opt);
}

int		parse_opt2(char *str, t_opt *opt)
{

  if (my_strlen(str) == 1 || str[0] != '-')
    {
      opt->arg = my_strdup(str);
      glob = 2;
    }
  if (str[0] == '-' && str[1] != '-')
    {
      opt->commande = my_strdup(str);
      if (function_op(opt) == -1)
	return (-1);
      glob = 1;
    }
}

int	      parse_opt(char *str, t_opt *opt)
{
  if (str[0] == '-' && str[1] == '-')
    {
      if (str[my_strlen(str) - 1] == '=' || str[my_strlen(str) - 2] == '='
	  || str[10] == '=')
	{
	  opt->commande = my_strdup(str);
	  glob = 1;
	}
      if (str[my_strlen(str) - 3] == '=' || str[my_strlen(str) - 2] == '='
	  || str[10] == '=')
	{
	  if (str[10] == '=')
	    opt->arg = my_strdup(str + 11);
	  else
	    opt->arg = my_strdup(str + (my_strlen(str) - 1));
	  glob = 2;
	}
    }
  else
    if (parse_opt2(str, opt) == -1)
      return (-1);
}

int		gestion_opt(int ac, char **av, t_opt *opt)
{
  int		i;
  char		**tab;

  i = 1;
  glob = 0;
  tab = look_for_d(av);
  while (i < ac)
    {
      if (i != ac && options(tab[i], opt, av) == 0)
	i++;
      if (i != ac && options(tab[i], opt, av) == 0)
	i++;
      if (i != ac)
	{
	  if (parse_opt(tab[i], opt) == -1)
	    return (-1);
	}
      if (glob == 2)
	{
	  if (point_opt(opt) == -1)
	    return (-1);
	  glob = 1;
	}
      i++;
    }
}
