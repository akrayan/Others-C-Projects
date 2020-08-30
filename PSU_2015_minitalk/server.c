/*
** server.c for server.c in /home/Rayan/Systeme_Unix2/PSU_2015_minitalk
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Feb  1 10:42:22 2016 AKKACHE Kaci
** Last update Sun Feb 21 20:44:12 2016 AKKACHE Kaci
*/

#include "./include/minitalk.h"

int	my_pid(int bit)
{
  int	        j;
  static int	new_pid = 0;
  static int	nb = 0;

  new_pid += bit;
  if (++nb >= 32)
    {
      nb = 0;
      j = new_pid;
      new_pid = 0;
      return (j);
    }
  else
    new_pid <<= 1;
  return (j);
}

void	my_disp(int check)
{
  static char	letter;
  static int	nb;
  static int	n = -1;
  static int	pid;

  n++;
  if (n < 32)
    pid = my_pid(check);
  else
    {
      letter = letter + (check << nb++) ;
      if (nb >= 8)
	{
	  if (letter == '\0')
	    n = -1;
	  my_putchar(letter);
	  letter = 0;
	  nb = 0;
	}
      kill(pid, SIGUSR1);
    }
}

void	my_sig(int sign)
{
  if (sign == SIGUSR1)
    my_disp(1);
  if (sign == SIGUSR2)
    my_disp(0);
}

void	my_verif(char *str)
{
  if (signal(SIGUSR1, my_sig) == SIG_ERR)
    {
      my_printf("%s : failed signal 1\n", str);
      exit(0);
    }
  if (signal(SIGUSR2, my_sig) == SIG_ERR)
    {
      my_printf("%s : failed signal 2\n", str);
      exit(0);
    }
}

int	main(int ac, char **av)
{
  pid_t pid;

  if (ac != 1)
    {
      my_printf("%s : Error arguments\n", av[0]);
      return (0);
    }
  pid = getpid();
  my_printf("%d\n", pid);
  my_verif(av[0]);
  while (42);
  return (0);
}
