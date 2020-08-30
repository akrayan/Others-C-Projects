/*
** my_strncmp.c for my_strncmp.c in /home/Rayan/Piscine_C_J06/ex_07
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Oct  5 23:58:20 2015 AKKACHE Kaci
** Last update Tue Oct  6 00:15:54 2015 AKKACHE Kaci
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

int     my_strncmp(char *s1, char *s2, int n)
{
  int   ls2;

  ls2 = my_strlen(s2);
  if (n < ls2)
    return (-1);
  else if (n == ls2)
    return (0);
  else
    return (1);
}

