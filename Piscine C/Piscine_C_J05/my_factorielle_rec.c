/*
** my_factorielle_rec.c for my_factorielle_rec.c in /home/Rayan/Piscine_C_J05
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Fri Oct  2 11:36:28 2015 AKKACHE Kaci
** Last update Mon Oct  5 21:59:57 2015 AKKACHE Kaci
*/
int     my_factorielle_rec(int nb)
{
  int	i;

  if (nb == 0)
    {
      return 1;
    }
  else if (nb < 0)
    {
      return 0;
    }
  i = my_factorielle_rec(nb - 1);
  nb = nb * i;

  return nb;
}
