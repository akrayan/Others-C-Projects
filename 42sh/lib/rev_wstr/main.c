#include "ex1.h"

static void	putword(char *str)
{
  int		i = 0;

  while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
    {
      my_putchar(str[i]);
      ++i;
    }
}

/* static int	number_words(char *str) */
/* { */
/*   int		i = 0; */
/*   int		max = 0; */
/*   int		flag = 0; */

/*   while (str[i]) */
/*     { */
/*       if ((str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')  && !flag) */
/* 	{ */
/* 	  ++max; */
/* 	  flag = 1; */
/* 	} */
/*       if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') */
/* 	{ */
/* 	  flag = 0; */
/* 	} */
/*       ++i; */
/*     } */
/*   return (max); */
/* } */

static int     mesterlen(char *str)
{
  int	i = 0;  
  while (str[i]) 
    {
      ++i;
    } 
  return i;
}

static void	reverse_all(char *str, int max)
{
  while (max)
    {
      while (max && str[max] != ' ' && str[max] != '\t' && str[max] != '\n')
	--max;
      putword((max) ? &str[max + 1]:&str[max]);
      if (max)
	my_putstr(" ");
      while (max && (str[max] == ' ' || str[max] == '\t' || str[max] == '\n'))
	--max;
    }
}

int		main(int ac, char **av)
{
  if (ac > 1)
    {
      reverse_all(av[1], mesterlen(av[1]));
    }
   my_putchar('\n');
  return (0);
}
