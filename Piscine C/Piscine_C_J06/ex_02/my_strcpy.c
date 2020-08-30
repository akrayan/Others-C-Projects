/*
** my_strcpy.c for my_strcpy.c in /home/Rayan/Piscine_C_J06/ex_02
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Oct  5 09:20:25 2015 AKKACHE Kaci
** Last update Mon Oct  5 10:10:38 2015 AKKACHE Kaci
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  
  i = 0; 
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
    return (dest);
}

