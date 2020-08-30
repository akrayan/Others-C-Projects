/*
** file_scene.c for rt2 in /home/nasrat_v/rendu/Infographie/gfx_raytracer2
**
** Made by
** Login   <nasrat_v@epitech.net>
**
** Started on  Fri May 20 01:09:44 2016
** Last update Tue May 24 09:53:13 2016 valentin nasraty
*/

#include "../include/rt.h"

char	*get_value(char *str)
{
  int	i;
  char	*stock;
  int	n;

  i = 0;
  n = 0;
  if ((stock = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (0);
  while (str[i] != ' ')
    i += 1;
  while (str[i])
    {
      if (str[i] == ';')
	{
	  stock[n] = '\0';
	  stock = epur_str(stock);
	  return (stock);
	}
      stock[n] = str[i];
      i += 1;
      n += 1;
    }
  stock[n] = '\0';
}

void	make_cmp_suite(t_s *s, t_lum *l)
{
  if (l->tab[l->i][0] == 'l' && l->tab[l->i][1] == 'x')
    l->x = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'l' && l->tab[l->i][1] == 'y')
    l->y = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'l' && l->tab[l->i][1] == 'z')
    l->z = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'l' && l->tab[l->i][1] == 'p')
    l->p = my_getnbr(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'l' && l->tab[l->i][1] == 'c' && l->tab[l->i][2] == 'o'
	   && l->tab[l->i][3] == 'l' && l->tab[l->i][4] == 'o' && l->tab[l->i][5] == 'r')
    l->c.full = cmp_color(get_value(l->tab[l->i]));
  else if (l->tab[l->i][0] == 'l' && l->tab[l->i][1] == 'u' && l->tab[l->i][2] == 'm')
    s->l_lum = add_elem(s->l_lum, NULL, l);
}

void	make_cmp(t_s *s, t_obj *o, t_obj *p, t_lum *l)
{
  l->i = -1;
  while (l->tab[++l->i])
    {
      if (l->tab[l->i][0] == 'x')
	o->x = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 'y')
	o->y = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 'z')
	o->z = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 't' && l->tab[l->i][1] == 'y' && l->tab[l->i][2] == 'p'
	       && l->tab[l->i][3] == 'e')
	o->type = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 'r')
	o->r = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 'a')
	o->a = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 'i')
	o->i = my_getnbr(get_value(l->tab[l->i]));
      else if (l->tab[l->i][0] == 'b')
	o->b = my_getnbr(get_value(l->tab[l->i]));
      else
	make_cmp_bis(s, o, p, l);
      make_cmp_suite(s, l);
    }
}

char	*read_file(char *filename)
{
  struct stat	sb;
  int		fd;
  int		l;
  char		*buffer;

  l = 0;
  if (stat(filename, &sb) == -1)
    return (0);
  if ((fd = open(filename, O_RDWR)) == -1)
    return (0);
  if ((buffer = malloc(sizeof(char) * sb.st_size)) == NULL)
    return (0);
  while (read(fd, buffer, sb.st_size) > 0);
  buffer[sb.st_size] = 0;
  close(fd);
  return (buffer);
}
