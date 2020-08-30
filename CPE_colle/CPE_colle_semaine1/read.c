/*
** read.c for read.c in /home/Rayan/CPE_colle_semaine1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Apr 26 19:02:29 2016 AKKACHE Kaci
** Last update Tue Apr 26 20:21:36 2016 AKKACHE Kaci
*/

#include "./include/maze.h"

char	*read_all(char *s, char *f)
{
  int	i;
  int	r;
  int	fd;
  char	b[11];


  if ((fd = open(f, O_RDONLY)) == -1)
    return (NULL);
  if ((r = read(fd, b, 10)) == -1)
    return (NULL);
  b[r] = '\0';
  i = 0;
  if ((s = malloc(r + 1)) == NULL)
    return (NULL);
  while (b[i] != '\0')
    {
      s[i] = b[i];
      i++;
    }
  s[i] = '\0';
  while ((r = read(fd, b, 10)) > 0)
    {
      if (r == -1)
	return (NULL);
      b[r] = '\0';
      if ((s = scat(s, sdup(b))) == NULL)
	return (NULL);
    }
  close(fd);
  return (s);
}
