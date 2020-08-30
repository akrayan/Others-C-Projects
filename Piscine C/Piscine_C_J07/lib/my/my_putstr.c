/*
** my_putstr.c for my_putstr.c in /home/Rayan/Piscine_C_J04
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Thu Oct  1 13:18:21 2015 AKKACHE Kaci
** Last update Tue Oct  6 13:31:27 2015 AKKACHE Kaci
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
