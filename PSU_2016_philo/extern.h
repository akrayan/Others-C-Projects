/*
** extern.h for  in /home/ernst_m/Documents/Tek2/philosophes/PSU_2016_philo
** 
** Made by ernst_m
** Login   <ernst_m@epitech.net>
** 
** Started on  Fri Mar 17 13:25:33 2017 ernst_m
** Last update Fri Mar 17 13:25:34 2017 ernst_m
*/

#ifndef __LIBRICEFEREE_EXTERN__
# define __LIBRICEFEREE_EXTERN__

#include <pthread.h>

int	RCFStartup(int ac, char **av);

void	RCFCleanup();

int	lphilo_eat();

int	lphilo_sleep();

int	lphilo_think();

int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);

int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* __LIBRICEFEREE_EXTERN__ */
