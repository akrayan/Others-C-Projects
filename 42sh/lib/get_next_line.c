/*
** get_next_line.c for get_next_line in /home/ham_l/rendu/Prog_elem_C_/CPE_2015_getnextline
** 
** Made by l ham
** Login   <ham_l@epitech.net>
** 
** Started on  Mon Jan  4 10:18:45 2016 l ham
** Last update Thu Jun  2 15:25:12 2016 VELLA CYRIL
*/

#include "../include/minishell.h"

int	my_strlenn(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*my_full_cat(char *str1, char *str2)
{
  int	size1;
  int	size2;
  char	*str3;

  size1 = my_strlenn(str1);
  size2 = my_strlenn(str2);
  str3 = malloc(sizeof(char) * (size1 + size2 + 1));
  str3[(size1 + size2)] = 0;
  size1 = 0;
  size2 = 0;
  while (str1[size1] != 0)
    {
      str3[size2] = str1[size1];
      size1 = size1 + 1;
      size2 = size2 + 1;
    }
  size1 = 0;
  while (str2[size1] != 0)
    {
      str3[size2] = str2[size1];
      size1 = size1 + 1;
      size2 = size2 + 1;
    }
  return (str3);
}

char	*my_cop_str(char *str, char *str2)
{
  int	i;

  i = 0;
  if ((str2 = malloc(sizeof(char) * (my_strlenn(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i = i + 1;
    }
  str2[i] = 0;
  return (str2);
}

char	*magic_str(char	**stock)
{
  int	c;
  char	*ok;
  char	*ret;

  c = 0;
  ok = malloc(sizeof(*stock) * 1);
  ok = my_cop_str(*stock, ok);
  while (ok[c] != '\0')
    {
      if (ok[c] == '\n')
	{
	  ok[c] = 0;
	  ret = malloc(sizeof(ok) * 1);
	  ret = my_cop_str(ok, ret);
	  *stock = my_cop_str(&ok[c + 1], *stock);
	  return (ret);
	}
      c = c + 1;
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  int		one;
  char		*ret;
  char		*buffer;
  static char	*stock = "\0";

  if ((ret = magic_str(&stock)) == NULL);
  else
    return (ret);
  if ((buffer = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  while ((one = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[one] = 0;
      stock = my_full_cat(stock, buffer);
      if ((ret = magic_str(&stock)) == NULL);
      else
	return (ret);
    }
  if (stock[0] == '\0')
    return (NULL);
  if ((ret = magic_str(&stock)) == NULL);
  else
    return (ret);
  return (stock);
}
