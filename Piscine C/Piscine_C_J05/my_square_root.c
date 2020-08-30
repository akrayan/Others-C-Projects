/*
** my_square_root.c for my_square_root in /home/afou_n/rendu/Piscine_C_J05
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Fri Oct  2 17:13:54 2015 Afou Nacerdine
** Last update Fri Oct  2 18:42:35 2015 Afou Nacerdine
*/

int	my_square_root(int nb)
{
  int	i;
  
  i = 0;
  if (nb == 1)
    {
      return (1);
    }
  while (i * i <= nb)
    {
      if ((i * i) == nb)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (0);
}
