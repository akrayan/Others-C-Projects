/*
** read.c for read.c in /home/Rayan/Colle/CPE_colle_semaine4
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 17 19:45:24 2016 AKKACHE Kaci
** Last update Tue May 17 21:53:20 2016 VELLA CYRIL
*/

#include	"./include/poke.h"

char		*s_c(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*s3;

  if ((s3 = malloc(my_strlen(s1) + my_strlen(s2) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (s1[i] != '\0')
    {
      s3[i] = s1[i];
      i++;
    }
  j = 0;
  while (s2[j] != '\0')
    {
      s3[i] = s2[j];
      i++;
      j++;
    }
  s3[i] = '\0';
  return (s3);
}

char		*s_dup(char *s)
{
  int	i;
  char	*r;

  i = 0;
  if ((r = malloc(my_strlen(s) + 1)) == NULL)
    return (NULL);
  while (s[i] != '\0')
    {
      r[i] = s[i];
      i++;
    }
  r[i] = '\0';
  return (r);
}

char		*rd_f(char *file)
{
  int	fd;
  char	b[10];
  char	*s;
  int	r;
  
  fd = open(s_c("pokecfg/", file), O_RDONLY);
  r = read(fd, b, 9);
  b[r] = '\0';
  s = s_dup(b);
  while ((r = read(fd, b, 9)) > 0)
    {
      b[r] = '\0';
      s = s_c(s, b);
    }
  return (s);
}

char		*read_all()
{
  DIR		*d;
  struct dirent	*e;
  char		*s;

  d = opendir("pokecfg");
  s = NULL;
  while ((e = readdir(d)) != NULL)
    {
      if (e->d_type == DT_REG && s == NULL)
	s = rd_f(e->d_name);
      else if (e->d_type == DT_REG)
	s = s_c(s_c(s, "\n"), rd_f(e->d_name));
    }
  return (s);
}
