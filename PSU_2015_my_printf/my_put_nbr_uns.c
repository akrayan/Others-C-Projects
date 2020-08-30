/*
** my_put_nbr_uns.c for my_put_nbr_uns.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:29:45 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:29:47 2015 AKKACHE Kaci
*/

void    my_put_nbr_uns(unsigned int nb)
{
  int   result;
  int   div;

  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
        {
          my_putchar('-');
          nb = nb * -1;
        }
      div = 1;
      while ((nb / div) >= 10)
        div = div * 10;
      while (div > 0)
        {
          result = (nb /div) % 10;
          my_putchar(48 + result);
          div = div / 10;
        }
    }
}
