/*
** cle.h for  in /home/vella_c/CPE_colle_semaine7
** 
** Made by VELLA CYRIL
** Login   <Cyril@epitech.net>
** 
** Started on  Mon Jun  6 18:22:10 2016 VELLA CYRIL
** Last update Mon Jun  6 21:24:02 2016 AKKACHE Kaci
*/

#ifndef _CLE_H_
# define _CLE_H_

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

int	s_len(char *s);
char	*s_dup(char *s);
char	*s_cat(char *s1, char *s2);
int	get_n(char *s);
int	decrypt(char *s, int nb);
int	crypt(char *s, int nb);
int	crypt2(char *s, int i, int nb, int fd);
char	*check(char *b, int *fd, int *r, char *f);
char	*read_all(char *f);
int	check_av(char **av);
int	my_putstr(char *str);

#endif /*_CLE_H_!*/

