/*
** my_get_nbr.c for  in /home/axel
** 
** Made by proust axel
** Login   <proust_c@epitech.net>
** 
** Started on  Wed Oct  7 18:38:38 2015 proust axel
** Last update Fri Oct  9 20:13:36 2015 proust axel
*/

int	my_getnbr(char *str)
{
  int	x;
  int	count;
  int	nb;
 
  x = 0;
  count = 0;
  nb = 0;
  while ((str[x] >= '0' && str[x] <= '9') || (str[x] == '+' || str[x] ==  '-'))
    {
      if (str[x] >= '0' && str[x] <= '9')
	nb = nb * 10 + (str[x] - 48);
      if (str[x] == '-')
	count = count + 1;
      x = x + 1;
    }
  if (count % 2 == 1)
    return (-nb);
  return (nb);
}
