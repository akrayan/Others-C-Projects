/*
** my_factorielle_it.c for my_factorielle_it.c in /home/Rayan/Piscine_C_J05
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Fri Oct  2 09:46:22 2015 AKKACHE Kaci
** Last update Mon Oct  5 21:59:24 2015 AKKACHE Kaci
*/
int	my_factorielle_it(int nb)
{
  int	i;
  int	j;
  
  i = 1;
  j = 1;
  if (nb == 0)
    {
      return 1;
    }
  if (nb < 0)
    {
      return 0;
    }
  while (i <= nb)
    {
      j = j * i;
      i = i + 1;
      
    }      
  return j;
}
