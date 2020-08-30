/*
** main.c for main.c in /home/Rayan/Systeme_Unix/PSU_2015_my_select
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Dec 13 17:15:59 2015 AKKACHE Kaci
** Last update Tue Dec 15 15:24:03 2015 AKKACHE Kaci
*/

#include "bsq.h"
#include "my.h"

int	nb_l(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 'o' || str[i] == '.' || str[i] == 'x')
	{
	  while (str[i] == 'o' || str[i] == '.' || str[i] == 'x')
	    i = i + 1;
	  nb = nb + 1;
	}
      i = i + 1;
    }
  return (nb);
}

char	**tab_for_bsq(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  tab = malloc(sizeof(char *) * nb_l(str) + 1);
  while (str[i] != '\0')
    {
      tab[k] = malloc(sizeof(char) * my_strlen(str));
      while (str[i] == '\n' || (str[i] >= '0' && str[i] <= '9'))
	i = i + 1;
      j = 0;
      while (str[i] == 'o' || str[i] == '.' || str[i] == 'x')
	{
	  tab[k][j] = str[i];
	  i = i + 1;
	  j = j + 1;
	}
      k = k + 1;
    }
  tab[k] = NULL;
  return (tab);
}

int	open_file(char *filepath)
{
  int	fd;

  fd = open(filepath, O_RDONLY);
  if (fd < 0)
    {
      my_putstr(filepath);
      my_putstr("error\n");
      exit(0);
    }
  return (fd);
}

char	*my_read_inf(char *filepath)
{
  struct stat	sb;
  int		fd;
  char		*buffer;

  fd = open_file(filepath);
  stat(filepath, &sb);
  if ((buffer = malloc(sizeof(char) * sb.st_size)) == NULL)
    return (NULL);
  read(fd, buffer, sb.st_size);
  close(fd);
  return (buffer);
}

int	main(int ac, char **av)
{
  char	*str;

  if (ac == 1)
    return (0);
  else
    {
      str = my_read_inf(av[1]);
      bsq(tab_for_bsq(str));
    }
  return (0);
}
