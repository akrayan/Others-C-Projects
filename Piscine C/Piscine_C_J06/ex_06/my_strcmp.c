/*
** my_strcmp.c for my_strcmp.c in /home/Rayan/Piscine_C_J06/ex_06
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Oct  5 23:09:21 2015 AKKACHE Kaci
** Last update Mon Oct  5 23:56:49 2015 AKKACHE Kaci
*/

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	ls1;
  int	ls2;

  ls1 = my_strlen(s1);
  ls2 = my_strlen(s2);
  if (ls1 < ls2)
    return (-1);
  else if (ls1 == ls2)
    return (0);
  else
    return (1);
}
