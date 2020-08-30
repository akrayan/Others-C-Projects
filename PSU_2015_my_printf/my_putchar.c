/*
** my_putchar.c for my_putchar.c in /home/Rayan/Systeme Unix/PSU_2015_my_printf
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Nov 14 12:28:35 2015 AKKACHE Kaci
** Last update Sat Nov 14 12:28:38 2015 AKKACHE Kaci
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
  compteur = compteur + 1;
}
