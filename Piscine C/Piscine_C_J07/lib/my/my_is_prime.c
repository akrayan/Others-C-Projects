/*
** my_is_prime.c for my_is_prime in /home/afou_n/rendu/Piscine_C_J05
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Fri Oct  2 18:51:52 2015 Afou Nacerdine
** Last update Fri Oct  2 19:24:12 2015 Afou Nacerdine
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb == 0 || nb == 1)
    {
      return (0);
    }
  while (i < nb)
    {
      if (nb % i == 0)
	{
	  return(0);
	}
      i = i + 1;
    }
  return (1);
}
