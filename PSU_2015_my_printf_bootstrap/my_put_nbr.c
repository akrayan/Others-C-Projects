/*
** my_put_nbr.c for my_put_nbr in /home/afou_n/Piscine_C_J03
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Wed Sep 30 18:11:14 2015 Afou Nacerdine
** Last update Thu Oct  1 20:47:05 2015 Afou Nacerdine
*/

int my_put_nbr(int nb)
{
  int number;

  number = 1;
  if (nb < 0)
    {
      my_putchar('-');
    }
  else if (nb > 0)
    {
      nb = nb * (-1);
    }
  while ((-9) > (nb / number))
    {
      number = number * 10;
    }
  while (1 <= number)
    {
      my_putchar('0' + ((nb / number) * (-1)));
      nb = nb % number;
      number = number / 10;
    }
  return (0);
}
