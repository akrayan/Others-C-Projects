/*
** cycle.c for  in /home/ernst_m/Documents/Tek2/philosophes/PSU_2016_philo
** 
** Made by ernst_m
** Login   <ernst_m@epitech.net>
** 
** Started on  Fri Mar 17 10:51:50 2017 ernst_m
** Last update Fri Mar 17 11:00:05 2017 ernst_m
*/

#include "philo.h"

void    *start(void *data)
{
  int   i;
  table *tab;

  tab = (table *)data;
  i = 0;
  while (i < tab->nbPhilos
	 &&pthread_equal (tab->philos[i].philo, pthread_self()) == 0)
    i++;
  while (tab->philos[i].nbEat < tab->maxEat)
    {
      if (tab->philos[i].state == EAT)
	eat(tab, i);
      else if (tab->philos[i].state == THINK)
	think(tab, i);
      else if (tab->philos[i].state == SLEEP)
	rest(tab, i);
    }
  return data;
}

void	eat(table *tab, int i)
{
  int	j;

  if (i == (tab->nbPhilos - 1))
    j = 0;
  else
    j = i + 1;
  pthread_mutex_trylock(&tab->chopsticks[i]);
  pthread_mutex_trylock(&tab->chopsticks[j]);
  lphilo_take_chopstick(&tab->chopsticks[i]);
  lphilo_take_chopstick(&tab->chopsticks[j]);
  lphilo_eat();
  tab->philos[i].state = SLEEP;
  tab->philos[i].nbEat++;
  lphilo_release_chopstick(&tab->chopsticks[i]);
  pthread_mutex_unlock(&tab->chopsticks[i]);
  lphilo_release_chopstick(&tab->chopsticks[j]);
  pthread_mutex_unlock(&tab->chopsticks[j]);
}

void	think(table *tab, int i)
{
  pthread_mutex_trylock(&tab->chopsticks[i]);
  lphilo_take_chopstick(&tab->chopsticks[i]);
  lphilo_think();
  tab->philos[i].state = EAT;
  lphilo_release_chopstick(&tab->chopsticks[i]);
  pthread_mutex_unlock(&tab->chopsticks[i]);
}

void	rest(table *tab, int i)
{
  lphilo_sleep();
  tab->philos[i].state = THINK;
}
