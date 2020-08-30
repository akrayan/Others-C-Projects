/*
** my_strcpy.c for my_strcpy in /home/axel/Piscine_C_J06
**
** Made by proust axel
** Login   <proust_c@epitech.net>
**
** Started on  Mon Oct  5 09:06:05 2015 proust axel
** Last update Mon Feb 15 15:26:47 2016 Axel Proust
*/

char	*my_strcpy(char *dest, char *src)
{
  int	c;

  c = 0;
  while (src[c] != '\0')
    {
      dest[c] = src[c];
      c = c + 1;
    }
  dest[c] = '\0';
  return (dest);
}
