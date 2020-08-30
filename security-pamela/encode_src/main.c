/*
** main.c for main in /home/billel/encode/bilbil/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 21:34:37 2017 BIllel
** Last update Wed Nov 29 19:11:50 2017 BIllel
*/

#include "pamela_encode.h"

int	my_full_encode(void)
{
  t_elem	*list = NULL;

  list = scDir(PATH_TO_ENCRYPT, list);
  create_file_encoded(list);
  free_list(list);
  return (0);
}

int	my_full_decode(void)
{
  t_elem	*list = NULL;

  list = scDir(PATH_TO_ENCRYPT, list);
  create_file_encoded2(list);
  free_list(list);
  return (0);
}
