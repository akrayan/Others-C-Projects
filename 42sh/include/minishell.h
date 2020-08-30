/*
** get_next_line.h for get_next_line in /home/vella/Desktop/rendu/Prog Elem/CPE_2015_getnextline
**
** Made by vella_c
** Login   <vella@epitech.net>
**
** Started on  Mon Jan 11 14:51:53 2016 vella_c
** Last update Fri Jun  3 02:37:56 2016 AKKACHE Kaci
*/

#ifndef READ_SIZE
#define READ_SIZE (1024)

#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

typedef struct s_c
{
  char		*p;
  int		r;
  int		f;
  int		status;
  int		fd[2];
  int		fd2[2];
  char		b[21];
  char		*o;
  char		**a1;
  pid_t		pid;
  pid_t		pid2;
}		t_c;

typedef struct s_list
{
  int	i;
  int	r;
  int	z;
  char	*tmp;
  char	*buffer;

}		t_list;

/*char	*do_pipe(char *a, t_cmd d);
char	*do_cmd(char *a, t_cmd d);
char	*do_chv(char *a, char *file, t_cmd d);
char	*do_dchv(char *a, char *file, t_cmd d);
char	*do_chva(char *a, char *file, t_cmd d);
char	*do_dchva(char *a, char *s, t_cmd d);*/

char		**cmd_tab(char *s);
char		*get_next_line(const int fd);
int		my_strlen(char *str);
char		*my_realloc(char *buffer, char *save);
char		**my_copy_env(char **env);
int		search_line(char **env, char *tab);
void		board(char **str);
int		check_it(char **tab);
char		*epur_str(char *str, int i);
char		*check_access(char **tab_path, char *str);
char		*my_strcpycat(char *str, char *buffer);
char		**my_alloc_tab(char *str, char **tab);
char		**my_str_to_wordtab(char *str);
int		find_word_in_env(char *str);
char		**str_to_wordtab_env(char *str);
char		**str_to_wordtab_pathname(char **tab);
char		**home(char **env);
char		**return_back(char **env);
char		**go_somewhere(char **env, char *pathname);
char		**my_cd(char *pathname, char **env);
int		my_search_line(char **env, char *tab);
char		*my_strdup(char *str);
int		my_tablen(char **str);
void		my_shell(char **env);
int		pid_bash(pid_t pid);
char		**my_exec(char **env, char **cmd);
int		check_builtins(char **cmd);
char		**my_pwd(char **env);
char		**search_path(char **env);
char		**make_builtins(char **env, char **cmd);
char		**my_add_env(char **env, char *name, char *cmd);
char		**my_add_env1(char **env, char *name);
char		**my_setenv2(char **env, char *tab);
char		**my_setenv(char **env, char *name, char *content);
char		**my_unsetenv(char **env, char *name);
char		*my_strncat(char *str, char *str2, int n);
char		*my_strcat(char *str, char *str1);
int		my_strcmp(char *s1, char *s2);
char		*my_strcpy(char *str, char *str1);
int		my_strncmp(char *s1, char *s2, int x);
void		my_prompt(char **env);
int		create_history(char *str);
int		stock_history(void);


#endif /* !READ_SIZE */
