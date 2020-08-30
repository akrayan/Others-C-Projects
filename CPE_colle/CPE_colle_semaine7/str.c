/*
** read.c for read.c in /home/Rayan/Colle/CPE_colle_semaine7
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Jun  6 18:06:32 2016 AKKACHE Kaci
** Last update Mon Jun  6 21:00:02 2016 AKKACHE Kaci
*/

# include "./include/cle.h"

int	s_len(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != '\0');
  return (i);
}

char	*s_dup(char *s)
{
  int	i;
  char	*r;

  if ((r = malloc(s_len(s) + 1)) == NULL)
    {
      write(1, "erreur malloc s_dup\n", s_len("erreur malloc s_dup\n"));
      return (NULL);
    }
  i = - 1;
  while (s[++i] != '\0')
    r[i] = s[i];
  r[i] = '\0';
  return (r);
}

char	*s_cat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*s3;

  if ((s3 = malloc(s_len(s1) + s_len(s2) + 1)) == NULL)
    {
      write(1, "erreur malloc s_cat\n", s_len("erreur malloc s_cat\n"));
      return (NULL);
    }
  i = -1;
  while (s1[++i] != '\0')
    s3[i] = s1[i];
  j = -1;
  while (s2[++j] != '\0')
    {
      s3[i] = s2[j];
      i++;
    }
  s3[i] = '\0';
  return (s3);
}

int	get_n(char *s)
{
  int	n;
  int	i;
  int	j;
  int	d;

  i = s_len(s) - 1;
  n = 0;
  while (i >= 0)
    {
      j = i;
      d = 1;
      while (j < s_len(s) - 1)
	{
	  d = d * 10;
	  j++;
	}
      n = n + (s[i] - 48) * d;
      i--;
    }
  return (n);
}

char	*check(char *b, int *fd, int *r, char *f)
{
  if ((*fd = open(f, O_RDONLY)) == -1)
    return (NULL);
  if ((b = malloc(11)) == NULL)
    {
      write(1, "erreur malloc read_all\n", s_len("erreur malloc read_all\n"));
      return (NULL);
    }
  if ((*r = read(*fd, b, 10)) == - 1)
    {
      write(1, "erreur read read_all\n", s_len("erreur read read_all\n"));
      return (NULL);
    }
  return (b);
}

