/*
** epure.c for epure.c in /home/Rayan/test/42sh
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Jun  2 16:41:15 2016 AKKACHE Kaci
** Last update Thu Jun  2 16:48:04 2016 AKKACHE Kaci
*/

int	c_e(char *s)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (s[i] == ' ' || s[i] == '\t')
    i++;
  while (s[i] != '\0')
    {
      if (s[i] == ' ' || s[i] == '\t')
	{
	  while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
	    i++;
	  if (s[i] != '\0')
	    n++;
	}
      if (s[i] != '\0')
	{
	  n++;
	  i++;
	}
    }
  return (n);
}

char	*e_s(char *s)
{
  int	j;
  int	i;
  char	*r;

  i = -1;
  j = 0;
  r = malloc(ee(s) + 1);
  while (s[++i] == ' ' || s[i] == '\t');
  while (s[i] != '\0')
    {
      if (s[i] == ' ' || s[i] == '\t')
	{
	  while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
	    i++;
	  if (s[i] != '\0')
	    {
	      r[j] = ' ';
	      j++;
	    }
	}
      if (s[i] != '\0')
	r[j++] = s[i++];
    }
  r[j] = '\0';
  return (r);
}

