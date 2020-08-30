/*
** canon.c for  in /home/axel/rendu/PSU/tetris_dossier/PSU_2015_tetris/debug
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Thu Mar 17 12:49:45 2016 Axel Proust
** Last update Sun Mar 20 12:30:06 2016 Axel Proust
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <termios.h>
#include <string.h>
#include "../tetris.h"

char				*verif_env(char **env)
{
  int				i;
  char				*buffer;

  i = -1;
  if (env == NULL)
    return (NULL);
  while (env[++i])
    if (strncmp(env[i], "TERM=", 5) == 0)
      {
	buffer = my_strdup(env[i]);
	return (buffer + 5);
      }
  return (NULL);
}

int				mode_canon(int n)
{
  static struct	termios		oldT;
  static struct termios		newT;
  char				c;

  if (n == 0)
    {
      ioctl(0,TCGETS, &oldT);
      ioctl(0,TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 1;
      ioctl(0,TCSETS,&newT);
    }
  if (n == 1)
    ioctl(0,TCSETS,&oldT);
}

/* int			main(int ac, char **av, char **env) */
/* { */
/*   char			*str; */
/*   int			i; */
/*   int			err; */

/*   if ((str = verif_env(env)) == NULL) */
/*     printf("ta grand mere \n"); */
/*   else */
/*     i = setupterm(str, 1, &err); */
/*   printf("result = %d, err = %d\n", i, err); */
/*   printf("%s\n", str); */
/* } */
