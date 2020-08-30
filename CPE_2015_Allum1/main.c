/*
** main.c for main.c in /home/Rayan/Prog_Elem2/CPE_2015_Allum1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Feb 10 10:09:29 2016 AKKACHE Kaci
** Last update Sun Feb 21 09:29:49 2016 AKKACHE Kaci
*/

#include "./include/allum.h"

char		**c_turn(char **t, int l)
{
  int		i;
  int		n;

  i = 0;
  n = 0;
  my_show_wordtab(t);
  while (nb_a(t[i]) < 1)
    i = (rand() % l) + 1;
  n = (rand() % nb_a(t[i])) + 1;
  my_printf("\nAI’s turn...\nAI removed %d match(es) from line %d\n", n, i);
  t = r_allum(t, i, n);
  return (t);
}

int		check_win(char **t, char tour)
{
  if (snb_a(t) == 0 && tour == 1)
    {
      my_show_wordtab(t);
      my_printf("I lost.. snif.. but I’ll get you next time!!\n");
      return (1);
    }
  else if (snb_a(t) == 0 && tour == 0)
    {
      my_show_wordtab(t);
      my_printf("You lost, too bad..\n");
      return (1);
    }
  return (0);
}

void		allum(int l, int al)
{
  char		**t;
  char		turn;
  char		end;

  turn = 0;
  end = 0;
  srand(time(NULL));
  t = init_tab();
  while (end == 0)
    {
      if (turn == 0)
	{
	  t = p_turn(t, l);
	  end = check_win(t, 0);
	  turn = 1;
	}
      else
	{
	  t = c_turn(t, l);
	  end = check_win(t, 1);
	  turn = 0;
	}
    }
}

int		main(int ac, char **av)
{
  allum(4, 7);
}
