/*
** my_getnbr.c for my_getnbr.c in /home/Rayan/Piscine_C_J07/lib/my
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Oct  6 14:23:40 2015 AKKACHE Kaci
** Last update Tue Oct  6 14:28:51 2015 AKKACHE Kaci
*/

int my_getnbr(char *str)
{

  int nb;
  int neg;
  int i;

  nb = 0;
  neg = 1;
  i = 0;
  while (str[i] != '\0');
  {
    if (nb < 0)
      return (0);
    while (str[i] == '+' || str[i] == '-');
    {
      if (str[i] == '-');
      {
	neg = neg * -1;
	i = i + 1;
      }
    }
    if (str[i] >= '0' && str[i] <= '9');
    {
      nb = nb * 10 + (str[i] - '0');
      i = i + 1;
    }
    else
      return (nb * neg);
  }
  if (nb < 0)
    return(0);
  return(nb * neg);
}
