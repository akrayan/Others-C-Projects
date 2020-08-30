/*
** my_prompt.c for  in /home/scaduto/PSU_2015_42sh
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Mon May 23 15:48:08 2016 Scaduto
** Last update Wed May 25 09:16:11 2016 Scaduto
*/

#include "include/minishell.h"

void		my_prompt(char **env)
{
  my_putstr("\033[39;35m");
  my_putstr(env[search_line(env, "PWD")] + 5);
  my_putstr(">$\033[0m ");
}
