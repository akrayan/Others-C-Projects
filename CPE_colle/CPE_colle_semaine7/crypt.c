/*
** main.c for main.c in /home/Rayan/Colle/CPE_colle_semaine7
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Jun  6 18:04:51 2016 AKKACHE Kaci
** Last update Mon Jun  6 21:23:18 2016 AKKACHE Kaci
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

int	crypt(char *s, int nb)
{
  int	fd;
  int	i;

  if ((fd = open("cesar", O_CREAT | O_WRONLY, S_IRUSR | S_IRGRP | S_IROTH))
      == -1)
    {
      write(1, "erreur open crypt\n", s_len("erreur open crypt\n"));
      return (-1);
    }
  i = -1;
  while (s[++i] != '\0')
    {
      if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
	{
	  if (crypt2(s, i, nb, fd) == -1)
	    return (-1);
	}
      else
	{
	  if (write(fd, &s[i], 1) == -1)
	    return (-1);
	}
    }
  return (1);
}

int	main(int ac, char **av)
{
  char	*s;
  int	nb;

  if (ac == 4)
    {
      if (check_av(av) == 0)
	return (0);
      if (av[1][0] != '\0' && av[1][1] == 'f')
	{
	  if ((s = read_all(av[2])) == NULL)
	    return (0);
	}
      else if ((s = s_dup(av[2])) == NULL)
	return (0);
      nb = get_n(av[3]) % 26;
      if (crypt(s, nb) == -1)
	return (0);
    }
  else
    my_putstr("Usage: ./decrypt -f/s filename/string n\n");
  return (0);
}
