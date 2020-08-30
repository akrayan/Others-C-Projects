/*
** fcn1.c for fcn1.c in /home/Rayan/Prog_Elem2/CPE_2015_Allum1
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Feb 21 09:26:53 2016 AKKACHE Kaci
** Last update Sun Feb 21 09:33:37 2016 AKKACHE Kaci
*/

#include "./include/allum.h"

char		*new_copy(char *str)
{
  int		i;
  char		*copy;

  i = 0;
  while (str[i++] != '\n');
  copy = malloc(sizeof(char) * i);
  i = 0;
  while (str[i] != '\n')
    {
      copy[i] = str[i];
      i = i + 1;
    }
  copy[i] = '\0';
  return (copy);
}

char		*read_st(const int fd)
{
  char		buffer[4096];
  char		*result;
  int		i;
  int		ret;

  i = 0;
  ret = read(fd, buffer, 4096);
  result = new_copy(buffer);
  return (result);
}

char		**init_tab()
{
  t_tab_var	var;

  var.t = malloc(sizeof(char *) * 6);
  var.t[0] = "*********";
  var.t[1] = "*   |   *";
  var.t[2] = "*  |||  *";
  var.t[3] = "* ||||| *";
  var.t[4] = "*|||||||*";
  var.t[5] = "*********";
  var.wt = malloc(sizeof(char *) * 7);
  var.i = 0;
  while (var.i < 6)
    {
      var.j = 0;
      var.wt[var.i] = malloc(10);
      while (var.t[var.i][var.j] != '\0')
	{
	  var.wt[var.i][var.j] = var.t[var.i][var.j];
	  var.j++;
	}
      var.wt[var.i][var.j] = '\0';
      var.i++;
    }
  var.wt[6] = NULL;
  return (var.wt);
}

int		nb_a(char *t)
{
  int		n;
  int		i;

  n = 0;
  i = 0;
  while (t[i] != '\0')
    {
      if (t[i] == '|')
	n++;
      i++;
    }
  return (n);
}

char		**r_allum(char **t, int i, int nb)
{
  int		j;

  j = 0;
  while (nb > 0)
    {
      if (t[i][j] == '|')
	{
	  t[i][j] = ' ';
	  nb--;
	}
      j++;
    }
  return (t);
}
