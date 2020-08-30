/*
** my_swap.c for my_swap.c in /home/Rayan/Piscine_C_J04
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Oct  1 12:54:04 2015 AKKACHE Kaci
** Last update Fri Oct  2 21:31:57 2015 AKKACHE Kaci
*/

int	my_swap(int *a, int*b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
