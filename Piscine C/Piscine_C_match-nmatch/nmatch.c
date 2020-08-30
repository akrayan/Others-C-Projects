/*
** nmatch.c for nmatch.c in /home/Rayan/Piscine_C_match-nmatch
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Oct 11 21:26:28 2015 AKKACHE Kaci
** Last update Sun Oct 11 22:36:29 2015 AKKACHE Kaci
*/

int     nmatch(char *s1, char *s2)
{
  int   i;
  int   j;
  int   r;
  int	t;

  i = 0;
  j = 0;
  r = 0;
  t = 0;
  while (s2[i] != '\0')
    {
      if (s2[i] == '*')
        {
          while (s1[j] != s2[i + 1] && s1[j] != '\0')
            {
              j = j + 1;
              r = 1;
            }
          if (s1[j] == '\0' && s2[i + 1] != '\0')
            {
              r = 0;
              j = 0;
            }
        }
      else if (s1[j] == s2[i])
        {
          r = 1;
          j = j + 1;
        }
      else
	r = 0;
      i = i + 1;
      if (s1[j] == '\0')
	{
	  t = t + r;
	  j = 0;
	}
    }
  return (t);
}
