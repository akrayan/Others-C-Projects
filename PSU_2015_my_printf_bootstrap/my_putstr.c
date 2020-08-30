/*
** my_putstr.c for my_putstr in /home/afou_n/rendu/Piscine_C_J04
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Thu Oct  1 11:37:40 2015 Afou Nacerdine
** Last update Fri Oct  9 16:33:13 2015 Afou Nacerdine
*/

int	my_putstr(char *str)
{
  int	count;
  
  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count = count + 1;
    }
  return (0);
}
