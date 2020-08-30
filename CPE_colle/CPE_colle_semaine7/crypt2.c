/*
** main.c for main.c in /home/Rayan/Colle/CPE_colle_semaine7
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Jun  6 18:04:51 2016 AKKACHE Kaci
** Last update Mon Jun  6 21:24:33 2016 AKKACHE Kaci
*/

#include "./include/cle.h"

int	crypt2(char *s, int i, int nb, int fd)
{
  char	c;

  if ((s[i] >= 'A' && s[i] <= 'Z' && s[i] + nb > 'Z') ||
      (s[i] >= 'a' && s[i] <= 'z' && s[i] + nb > 'z'))
    s[i] = s[i] - 26;
  c = s[i] + nb;
  if (write(fd, &c, 1) == -1)
    return (-1);
  return (1);
}

int	check_av(char **av)
{
  if (av[3][0] == '-')
    {
      my_putstr("entrez un nombre positif\n");
      return (0);
    }
  return (1);
}
