/*
** my_put_nbr.c for my_put_nbr.C in /home/Rayan/Piscine_C_J03
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Sep 30 19:26:19 2015 AKKACHE Kaci
** Last update Tue Oct  6 13:18:46 2015 AKKACHE Kaci
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
