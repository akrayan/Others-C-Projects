/*
1;2802;0c** my_history.c for  in /home/scaduto/PSU_2015_42sh
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Mon May 30 13:43:49 2016 Scaduto
** Last update Thu Jun  2 13:14:12 2016 Scaduto
*/

#include "./include/minishell.h"

int	create_history(char *str)
{
  int	fd;

  if ((fd = open("./.history" , O_CREAT | O_RDWR | O_APPEND, 0666)) == -1)
    return (-1);
  write(fd, str, my_strlen(str));
  write(fd, "\n", 1);
  close(fd);
}
