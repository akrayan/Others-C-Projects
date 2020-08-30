/*
** my_revstr.c for  in /home/scaduto/PSU_2015_42sh/lib
**
** Made by Scaduto
** Login   <scaduto@epitech.net>
**
** Started on  Tue May 31 10:24:36 2016 Scaduto
** Last update Tue May 31 10:25:23 2016 Scaduto
*/

char	*my_revstr(char *str)
{
  int	i;
  int	imax;
  char	r;

  i = 0;
  imax = 0;
  r = 0;
  while (str[imax] != '\0')
    imax = imax + 1;
  imax = imax - 1;
  while (i < imax)
    {
      r = str[i];
      str[i] = str[imax];
      str[imax] = r;
      i = i + 1;
      imax = imax - 1;
    }
  return (str);
}
