/*
** main.c for main in /home/billel/encode/bilbil/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 21:34:37 2017 BIllel
** Last update Sat Nov 25 22:23:37 2017 BIllel
*/

#include "pamela_encode.h"

int	main(void)
{
  t_elem	*list = NULL;

  list = scDir(PATH_TO_ENCRYPT, list);
  create_file_encoded(list);
  free_list(list);
  return (0);
}
