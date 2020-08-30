/*
** shell.h for shell.c in /home/Rayan/Shell/PSU_2015_minishell2
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Mar 29 16:44:05 2016 AKKACHE Kaci
** Last update Tue Apr 12 20:38:07 2016 AKKACHE Kaci
*/

#ifndef MYSH_H
# define MYSH_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "./my.h"

typedef struct s_l
{
  struct s_l  	*last;
  struct s_l   	*next;
  char		*s;
}		t_l;

typedef struct s_se
{
  t_l		*p;
  t_l		*f;
  t_l		*l2;
  int		j;
}		t_se;

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

typedef struct s_cmd
{
  t_l		*path;
  t_l		*env;
  char		*s;
}		t_cmd;

typedef struct s_main
{
  int		fd[2];
  int		st;
  char		**cmd;
  t_cmd		d;
  char		b[4096];
  char		*n;
  int		i;
  int		j;
  pid_t		p;
}		t_main;

t_main		m1(t_main m);
t_main		m2(t_main m);
t_main		m3(t_main m);
t_main		m4(t_main m);
t_main		m5(t_main m);
t_main		m6(t_main m);
t_main		m7(t_main m);
t_main		m8(t_main m);
t_main		m9(t_main m);
t_main		m10(t_main m);
t_l		*add_elem(char *s, t_l *l);
t_l		*sup_elem(t_l *l, int i);
t_l		*g_e(char **t, t_l *l);
t_l		*s_e(t_l *env, char *arg);
t_l		*us_e(t_l *env, char *arg);
void		free_list(t_l *l);
void		show_l(t_l *l);
char		**l_tab(t_l *e);
int		nbc2(char *s, char c, int k);
int		nbc(char *s, char c);
char		**s_t_w(char *s, char c);
t_l		*g_path2(char *t, t_l *path, char c);
t_l		*g_path(char **t, t_l *path);
char		*init_s();
char		*sc(char *s1, char *s2, char c);
char		*s_space(char *s);
int		c_s3(char *s);
char		**cmd_tab(char *s);
void		exec(t_l *path, t_l *env, char *a);
char		*l_t_s(t_l *l);
void		aff_fd(t_l *l, int fd);
int		error_c(t_l *path, char *s);
int		error_l(char **t);
char		*do_pipe(char *a, t_cmd d);
char		*do_cmd(char *a, t_cmd d);
char		*do_chv(char *a, char *file, t_cmd d);
char		*do_dchv(char *a, char *file, t_cmd d);
char		*do_chva(char *a, char *file, t_cmd d);
char		*do_dchva(char *a, char *s, t_cmd d);

#endif
