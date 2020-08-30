/*
** main.c for main.c in /home/Rayan/Piscine_C_bistromathique
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Sat Oct 31 18:09:31 2015 AKKACHE Kaci
** Last update Tue Nov  3 23:03:17 2015 AKKACHE Kaci
*/

#include <stdlib.h>
#include <unistd.h>



char	*trad(char *expr, char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  while (expr[i] != '\0')
    {
      j = 0;
      while (s1[j] != '\0')
	{
	  if (expr[i] == s1[j])
	    expr[i] = s2[j];
	  j = j + 1;
	}
      i = i + 1;
    }
  return (expr);
}

int	main(int ac, char **av)
{
  char	*expr;
  char	*listnb;
  char	*listop;
  int	err;

  expr = malloc(my_getnbr(av[3]));
  listnb = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  listop = "()+-*/%";
  read(0, expr, my_getnbr(av[3]));
  expr[my_getnbr(av[3])] =  '\0';
  expr = trad(expr, av[1], listnb);
  expr = trad(expr, av[2], listop);
  err = syntax_error(expr);
  if (err == 1)
    return (0);
  my_putstr(eval_expr(add_space(expr)));
  return (0);
}
