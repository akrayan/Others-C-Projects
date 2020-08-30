/*
** my_power_rec.c for my_power_rec.c in /home/Rayan/Piscine_C_J05
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Fri Oct  2 12:08:46 2015 AKKACHE Kaci
** Last update Mon Oct  5 21:40:31 2015 AKKACHE Kaci
*/

int     my_power_rec(int nb, int power)
{
  int	i;

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
  i = my_power_rec(nb, power -1);
  nb = nb * i;

  return nb;
}
