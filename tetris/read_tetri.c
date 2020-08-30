/*
** main.c for  in /home/axel/rendu/PSU/PSU_2015_tetris
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Tue Feb 23 14:09:44 2016 Axel Proust
** Last update Sun Mar 20 22:15:27 2016 AKKACHE Kaci
*/

#include "tetris.h"

int     tab_len(char **tab)
{
  int   j;

  j = 0;
  while (tab[j] != NULL)
    j++;
  return (j);
}

int		check_error(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*' ||
	  str[i] == ' ' || str[i] == '\n')
	i++;
      else
	return (0);
    }
  return (1);
}


char		*open_file(char *file, char *str, t_te *te)
{
  int		fd;
  char		*buffer;
  char		*result;
  struct stat   block;
  static int	c = 0;

  stat(file, &block);
  if ((buffer = malloc(sizeof(char) * block.st_size)) == NULL)
    return (0);
  memset(buffer, 0, sizeof(char) * block.st_size);
  result = str_copy3(file, str);
  if ((fd = open(result, O_RDONLY)) == -1)
    return (NULL);
  if (read(fd, buffer, block.st_size) <= 0)
    return (NULL);
  if ((te->tab_def[c] = malloc(sizeof(char) * my_strlen(buffer))) == NULL)
    return (NULL);
  te->tab_def[c] = buffer;
  c++;
}

char		*open_directory(char *file)
{
  DIR		*rep;
  struct dirent	*lecture;
  struct stat	def;
  char		*result;
  int		i;


  i = 0;
  if ((rep = opendir("./tetriminos")) == NULL)
    return (NULL);
  lecture = readdir(rep);
  stat(lecture->d_name, &def);
  while (lecture = readdir(rep))
    {
      if (have_ptet(lecture->d_name, 0) == 1)
	{
	  if (i >= 1)
	      result = str_copy(result, lecture->d_name);
	  else
	    result = my_strdup(lecture->d_name);
	  i++;
	}
    }
  return (result);
}

int		read_tet(t_te *te)
{
  char		*str;
  char		*result;
  char		**tab_tetri;
  int		i;

  i = -1;
  if ((result = open_directory("lol")) == NULL)
    return (-1);
  te->tab_tetri = str_to_wordtab(result, '\n');
  if ((te->tab_def = malloc(sizeof(char *) * (tab_len(te->tab_tetri) + 1))) == NULL)
    return (-1);
  while (te->tab_tetri[++i])
    {
      if (open_file("./tetriminos", te->tab_tetri[i], te) == NULL)
	return (NULL);
    }
  te->tab_def[i] = NULL;
  i = 0;
}
