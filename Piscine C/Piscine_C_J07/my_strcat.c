/*
** my_strcat.c for my_strcat.c in /home/Rayan/Piscine_C_J07
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue Oct  6 16:06:48 2015 AKKACHE Kaci
** Last update Tue Oct  6 16:24:50 2015 AKKACHE Kaci
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;  
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
}
