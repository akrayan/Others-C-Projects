/*
** philo.h for  in /home/ernst_m/Documents/Tek2/philosophes/PSU_2016_philo
**
** Made by ernst_m
** Login   <ernst_m@epitech.net>
**
** Started on  Mon Mar 13 15:10:26 2017 ernst_m
** Last update Fri Mar 17 10:56:34 2017 ernst_m
*/

#ifndef _PHILO_H_
#define _PHILO_H_
#include "extern.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef enum State{
  THINK,
  EAT,
  SLEEP
} State;

typedef struct philosophe {
  State		        state;
  pthread_t		philo;
  int			nbEat;
}		philosophe;

typedef	struct table {
  pthread_mutex_t	*chopsticks;
  pthread_cond_t	*conditions;
  int			nbPhilos;
  int			maxEat;
  philosophe		*philos;
}		table;

void    eat(table *tab, int i);
void    think(table *tab, int i);
void    rest(table *tab, int i);
void    *start(void *data);

#endif /*_PHILO_H*/
