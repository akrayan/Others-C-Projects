/*
** my_strncpy.c for my_strncpy.c in /home/Rayan/Piscine_C_J06/ex_03
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Mon Oct  5 10:19:13 2015 AKKACHE Kaci
** Last update Mon Oct  5 11:50:18 2015 AKKACHE Kaci
*/

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	l;

  i = 0;  
  l = my_strlen(dest);
  while (src[i] != '\0')
    {   
      dest[i] = src[i];
      i = i + 1;
    }	   
  if (l < n)
    {      
      dest[i] = '\0';
    }    
  return (dest);
}
