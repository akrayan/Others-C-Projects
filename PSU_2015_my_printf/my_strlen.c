/*
** my_strlen.c for my_strlen.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:32:44 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:32:47 2015 AKKACHE Kaci
*/

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    count = count + 1;
  return (count);
}
