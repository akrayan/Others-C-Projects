/*
** str.c for  in /home/vella_c/CPE_colle_semaine4
** 
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
** 
** Started on  Tue May 17 18:42:47 2016 VELLA CYRIL
** Last update Tue May 17 21:56:02 2016 VELLA CYRIL
*/
#include	"./include/poke.h"

char		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
}

int		my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (my_putchar(str[i]) == -1)
      return (-1);
  return (i);
}

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}

int		my_putnbr(int nb)
{
  int		n;

  n = nb % 10;
  nb = nb / 10;
  if (nb > 0)
    my_putnbr(nb);
  if (my_putchar(n + 48) == -1)
    return (-1);
}

int		gnb(char *s)
{
  int		i;
  int		j;
  int		nb;
  int		d;

  nb = 0;
  i = my_strlen(s) - 1;
  while (i >= 0)
    {
      d = 1;
      j = 0;
      while (j < my_strlen(s) - i - 1)
	{
	  d = d * 10;
	  j++;
	}
      nb = nb + ((s[i] - 48) * d);
      i--;
    }
  return (nb);
}
