/*
** main.c for main.c in /home/Rayan/Colle/CPE_colle_semaine7
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Jun  6 18:04:51 2016 AKKACHE Kaci
** Last update Mon Jun  6 21:20:58 2016 AKKACHE Kaci
*/

#include "./include/cle.h"

char	my_putchar(char c)
{
  return (write(1, &c, 1));
}

int	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
  return (i);
}

char	*read_all(char *f)
{
  int	fd;
  int	r;
  char	*s;
  char	*b;

  b = NULL;
  if ((b = check(b, &fd, &r, f)) == NULL)
    return (NULL);
  b[r] = '\0';
  if ((s = s_dup(b)) == NULL)
    return (NULL);
  while (r > 0)
    {
      if ((r = read(fd, b, 10)) == - 1)
	{
	  write(1, "erreur read read_all\n", s_len("erreur read read_all\n"));
	  return (NULL);
	}
      else if (r > 0)
	{
	  b[r] = '\0';
	  if ((s = s_cat(s, b)) == NULL)
	    return (NULL);
	}
    }
  return (s);
}

int	decrypt(char *s, int nb)
{
  int	i;

  i = 0;
  while (s[i] != '\0')
    {
      if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
	{
	  if ((s[i] >= 'A' && s[i] <= 'Z' && s[i] + nb > 'Z') ||
	      (s[i] >= 'a' && s[i] <= 'z' && s[i] + nb > 'z'))
	    s[i] = s[i] - 26;
	  if (my_putchar(s[i] + nb) == -1)
	    return (-1);
	}
      else
	{
	  if (my_putchar(s[i]) == -1)
	    return (-1);
	}
      i++;
    }
  return (1);
}

int	main(int ac, char **av)
{
  char	*s;
  int	nb;

  if (ac == 3)
    {
      if (av[2][0] == '-')
	{
	  my_putstr("entrez un nombre positif\n");
	  return (0);
	}
      if ((s = read_all(av[1])) == NULL)
	return (0);
      nb = get_n(av[2]) % 26;
      if (decrypt(s, nb) == -1)
	return (0);
    }
  else
    my_putstr("Usage: ./decrypt filename n\n");
  return (0);
}
