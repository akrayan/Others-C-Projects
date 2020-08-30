/*
** main.c for main.c in /home/rayan/Concurence/PSU_2016_philo
**
** Made by Rayan
** Login   <raihane.akkache@epitech.net>
**
** Started on  Mon Mar 13 11:56:14 2017 Rayan
** Last update Fri Mar 17 10:59:25 2017 ernst_m
*/

#include "philo.h"

int	check(char **av, int *p, int *e)
{
  if (strcmp(av[1], "-p") == 0)
    {
      *p = atoi(av[2]);
      if (strcmp(av[3], "-e") == 0)
	{
	  *e = atoi(av[4]);
	  return 0;
	}
      else
	return (-1);
    }
  else if (strcmp(av[1], "-e") == 0)
    {
      *e = atoi(av[2]);
      if (strcmp(av[3], "-p") == 0)
	{
	  *p = atoi(av[4]);
	  return 0;
	}
      else
	return (-1);
    }
  return (-1);
}

int	check_end(table *tab)
{
  int	i;

  i = 0;
  while (i < tab->nbPhilos)
    {
      if (tab->philos[i].nbEat >= tab->maxEat)
	return (0);
      i++;
    }
  return (1);
}

int	init_table(table *tab)
{
  int	i;

  if ((tab->chopsticks = malloc(sizeof(pthread_mutex_t) * tab->nbPhilos))
      == NULL
      || (tab->conditions = malloc(sizeof(pthread_cond_t) * tab->nbPhilos))
      == NULL
      || (tab->philos = malloc(sizeof(philosophe) * tab->nbPhilos)) == NULL)
    return -1;
  i = 0;
  while (i < tab->nbPhilos)
    {
      pthread_mutex_init(&tab->chopsticks[i], NULL);
      pthread_cond_init(&tab->conditions[i], NULL);
      i++;
    }
  i = 0;
  while (i < tab->nbPhilos)
    {
      tab->philos[i].state = i % 3;
      tab->philos[i].nbEat = 0;
      if (pthread_create(&(tab->philos[i].philo), NULL, start, tab) != 0)
	return (-1);
      i++;
    }
  return (0);
}

void	wait_all_thread(table *tab)
{
  int	i;

  i = 0;
  while (i < tab->nbPhilos)
    {
      pthread_join (tab->philos[i].philo, NULL);
      i++;
    }
}

int	main(int ac, char **av)
{
  table	tab;

  if (ac != 5)
    {
      return (1);
    }
  if (check(av, &(tab.nbPhilos), &(tab.maxEat)) == -1)
    return (1);
  if (tab.nbPhilos < 2)
    return (1);
  RCFStartup(ac, av);
  if (init_table(&tab) == -1)
     return (1);
  wait_all_thread(&tab);
  RCFCleanup(ac, av);
}
