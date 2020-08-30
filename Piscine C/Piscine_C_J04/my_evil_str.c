/*
** my_evil_str.c for my_evil_str.c in /home/Rayan/Piscine_C_J04
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Fri Oct  2 21:24:33 2015 AKKACHE Kaci
** Last update Fri Oct  2 21:29:56 2015 AKKACHE Kaci
*/
int my_swapp(char *a, char *b)
{
  char	count;

  count = *a;
  *a = *b;
  *b = count;
}

char *my_evil_str(char *str)
{
  int	x;
  int	y;

  x = my_strlen(str) - 1;
  y = 0;
  while (x > y)
    {
      my_swapp(&str[x], &str[y]);
      x = x - 1;
      y = y + 1;
    }
  return (str);
}
