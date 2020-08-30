/*
** minitalk.h for minitalk.h in /home/Rayan/Systeme_Unix2/PSU_2015_minitalk/include
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Feb 21 20:43:27 2016 AKKACHE Kaci
** Last update Sun Feb 21 20:43:44 2016 AKKACHE Kaci
*/

#ifndef MINITALK_H_
# define MINITALK_H_

#include <signal.h>
#include "my.h"

#endif /* !MINITALK_H_ */
/* In ./server/server.c */
int			my_pid(int bit);
void			my_disp(int check);
void			my_sig(int sign);
void			my_verif(char *str);
int			main(int ac, char **av);
/* In ./client/client.c */
void			my_send_pid(int pid);
void			my_send(int pid, char letter);
void			my_test(int sign);
int			main(int ac, char **av);
