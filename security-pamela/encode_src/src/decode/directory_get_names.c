/*
** directory_get_names.c for gestiob in /home/billel/encode/bilbil/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 21:38:03 2017 BIllel
** Last update Sun Nov 26 04:50:39 2017 BIllel
*/

#include "pamela_encode.h"

t_elem	*scDir(char *nameDir, t_elem *list)
{
  char	*path;
  DIR	*dir;
  struct dirent *entry;
  
  dir = opendir(nameDir);
  while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_name[0] != '.')
	{
	  path = malloc(strlen(entry->d_name) + strlen(nameDir) + 2);
	  strcpy(path, nameDir);
	  strcat(path, "/");
	  strcat(path, entry->d_name);
	  if (entry->d_type == DT_DIR)
	    list = add_elem(list, path, strlen(path), nameDir, 'd');
	  else
	    list = add_elem(list, path, strlen(path), nameDir, 'f');
	  if (entry->d_type == DT_DIR)
	    list = scDir(path, list);
	}
    }
  closedir(dir);
  return (list);
}
