/*
** my_strlen.c for my_strlen in /home/Rayan/Piscine_C_J04
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Oct  1 16:45:30 2015 AKKACHE Kaci
** Last update Tue Oct  6 13:32:19 2015 AKKACHE Kaci
*/
int     my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return i;
}
