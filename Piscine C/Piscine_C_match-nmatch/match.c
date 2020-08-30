/*
** match.c for match.c in /home/Rayan/Piscine_C_match-nmatch
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Oct 11 19:30:12 2015 AKKACHE Kaci
** Last update Sun Oct 11 22:39:11 2015 AKKACHE Kaci
*/

int	match(char *s1, char *s2)
{
  int	i;
  int	j;
  int	r;
  
  i = 0;
  j = 0;
  r = 0;
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
    }
  return (r);
}
