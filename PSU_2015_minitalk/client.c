/*
** client.c for client.c in /home/Rayan/Systeme_Unix2/PSU_2015_minitalk
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Feb  1 11:10:14 2016 AKKACHE Kaci
** Last update Sun Feb 21 20:39:33 2016 AKKACHE Kaci
*/

#include "./include/minitalk.h"

int	global = 0;

void	my_send_pid(int pid)
{
  int	my_pid;
  int	decal;

  my_pid = getpid();
  decal = 31;
  while (decal >= 0)
    {
      if (((my_pid >> decal) & 1) == 1)
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      usleep(400);
      decal--;
    }
}

void	my_send(int pid, char letter)
{
  int	decal;

  decal = -1;
  while (++decal < 8)
    {
      global = 0;
      if (((letter >> decal) & 1) == 1)
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      while (global != 1);
    }
}

void	my_test(int sign)
{
  if (sign == SIGUSR1)
    global = 1;
}

int	main(int ac, char **av)
{
  int	pid;
  int	i;

  if (ac != 3)
    return (write(1, "Error arguments\n", 17));
  pid = my_getnbr(av[1]);
  my_send_pid(pid);
  i = 0;
  if ((signal(SIGUSR1, my_test)) == SIG_ERR)
    {
      my_printf("%s : failed signal 1\n", av[0]);
      return (0);
    }
  while (av[2][i] != '\0')
    {
      my_send(pid, av[2][i]);
      i = i + 1;
    }
  my_send(pid, av[2][i]);
  return (0);
}
