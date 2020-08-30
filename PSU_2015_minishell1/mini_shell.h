/*
** mini_shell.h for mini_shell.h in /home/Rayan/Systeme_Unix/PSU_2015_minishell1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Jan 21 15:44:51 2016 AKKACHE Kaci
** Last update Sun Jan 24 22:53:07 2016 AKKACHE Kaci
*/

#ifndef MINI_SHELL
# define MINI_SHELL

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

char	**process_pere(char **env, char *s);
char	**add_elem(char **t, char *s);
char	**sup_elem(char **t, int k);
char	**s_env(char **env, char **arg);
char	**s_env2(char **env, char **arg, int r);
char	**us_env(char **env, char **arg);
char	**tab_for_shell(char *str);
char	**tab_for_path(char *str);
char	**get_path(char **env);
char	*strcat2(char *s1, char *s2);
char	*new_copy(char *str);
char	*read_st(const int fd);
char	*cp_dump(char *s);
int	cd(char **arg, char **env);
int	nb_l(char *str);
int	nb_dbpoint(char *str);
int	is_e(char *s1, char *s2);
int	is_ee(char *s1, char *s2);
int	ex_bin(char **arg, char **env);
int	ex_norm(char **arg, char **env);
int	ex_cmd(char *cmd, char **env);
int	nb_arg(char **arg);
int	s_wt(char **t);

#endif
