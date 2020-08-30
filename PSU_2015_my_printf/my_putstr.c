/*
** my_putstr.c for my_putstr.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:31:07 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:31:10 2015 AKKACHE Kaci
*/

void	my_putstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count = count + 1;
    }
}
