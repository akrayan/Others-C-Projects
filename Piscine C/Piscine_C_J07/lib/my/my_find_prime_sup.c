/*
** my_find_prime_sup.c for my_find_prime_sup in /home/afou_n/rendu/Piscine_C_J05
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Fri Oct  2 19:29:11 2015 Afou Nacerdine
** Last update Mon Oct  5 22:01:40 2015 AKKACHE Kaci
*/

int	my_find_prime_sup(int nb)
{

  while (my_is_prime(nb) == 0)
    {
      nb = nb + 1;
    }
  return (nb);
}