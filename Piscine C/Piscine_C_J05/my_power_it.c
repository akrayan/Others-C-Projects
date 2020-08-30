/*
** my_power_it.c for my_power_it.c in /home/Rayan/Piscine_C_J05
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Fri Oct  2 10:48:47 2015 AKKACHE Kaci
** Last update Mon Oct  5 22:00:29 2015 AKKACHE Kaci
*/
int     my_power_it(int nb, int power)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  if (power == 0)
    {
      return 1;
    }
  else if (power <= 0)
    {  
      return 0;
    }
  else if (nb <  0)
    {
      nb = nb * (-1);
    }
  while (i <= power)
    {
      j = nb * j;
      i = i + 1;
    }
  return j;
}
