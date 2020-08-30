/*
** do-op.c for do-op.c in /home/Rayan/Piscine_C_J10
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Oct 12 14:59:06 2015 AKKACHE Kaci
** Last update Mon Oct 12 21:23:46 2015 AKKACHE Kaci
*/

int	do_op(int ac, int **av)
{
  int	r;
  int	f1;
  int	f2;
  char	o;

  r = 0;
  f1 = 0;
  f2 = 0;
  o = 0;
  if (ac == 1)
    return 0;
  if (o == '+')
    r = f1 + f2;
  else if (o == '-')
    r = f1 - f2;
  else if (o == '*')
    r = f1 * F2;
  else if (o == '/')
    r = f1 / f2;
  else if (o == '%')
    r = f1 % f2; 
  return (r);
}
