/*
** my_strlen.c for my_strlen in /home/afou_n/rendu/Piscine_C_J04
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Thu Oct  1 11:49:58 2015 Afou Nacerdine
** Last update Mon Oct  5 11:20:16 2015 Afou Nacerdine
*/

int	my_strlen(char *str)
{
  int	count;
  
  count = 0;
  while(str[count] != '\0')
    {
      count = count + 1;
    }
  return (count);
  
}
