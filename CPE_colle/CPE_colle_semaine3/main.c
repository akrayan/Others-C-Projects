/*
** main.c for main.c in /home/Rayan/Colle
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 10 18:20:13 2016 AKKACHE Kaci
** Last update Tue May 10 21:55:35 2016 AKKACHE Kaci
*/

#include "./include/gm.h"

char			**init_map(int x, int y)
{
  int			i;
  int			j;
  char			**t;

  if((t = malloc(sizeof(char *) * y)) == NULL)
    return (NULL);
  j = 0;
  while (j < y)
    {
      i = 0;
      if((t[j] = malloc(x)) == NULL)
	return (NULL);
      while (i < x)
	{
	  t[j][i] = 1;
	  i++;
	}
      j++;
    }
  return (t);
}

void			fill_it(t_bunny_pixelarray *p, t_color c)
{
  int			i;
  unsigned char		*pix;

  i = 0;
  pix = p->pixels;
  while (i < 4 * p->clipable.clip_width * p->clipable.clip_height)
    {
      pix[i] = c.argb[0];
      pix[i + 1] = c.argb[1];
      pix[i + 2] = c.argb[2];
      pix[i + 3] = c.argb[3];
      i = i + 4;
    }
}

void			put_img_c(t_bunny_pixelarray *p, t_bunny_pixelarray *i, t_bunny_position pos, t_bunny_position pos3, t_bunny_position pos4)
{
  t_bunny_position	pos1;
  t_bunny_position	pos2;
  unsigned int		*pix;
  unsigned int		*img;

  pix = p->pixels;
  img = i->pixels;
  pos1.y = pos4.y * (i->clipable.clip_height / pos3.y);
  pos2.y = pos.y;
  while (pos1.y < (pos4.y + 1) * (i->clipable.clip_height / pos3.y))
    {
      pos1.x = pos4.x * (i->clipable.clip_width / pos3.x);
      pos2.x = pos.x;
      while (pos1.x < (pos4.x + 1) * (i->clipable.clip_width / pos3.x))
	{
	  if (img[(pos1.y * i->clipable.clip_width) + pos1.x] != img[0])
	    pix[(pos2.y * p->clipable.clip_width) + pos2.x] = img[(pos1.y * i->clipable.clip_width) + pos1.x];
	  pos1.x++;
	  pos2.x++;
	}
      pos1.y++;
      pos2.y++;
    }
}

void			aff_map(t_s *s)
{
  t_bunny_position	p;

  s->p1.x = 6;
  s->p1.y = 1;
  p.y = 0;
  s->p.y = 100;
  s->p2.y = 0;
  while (p.y < s->t.y)
    {
      //write(1, "lol", 3);
      p.x = 0;
      s->p.x = 10;
      while (p.x < s->t.x)
	{
	  s->p2.x = s->m[p.y][p.x];
	  put_img_c(s->pix, s->img, s->p, s->p1, s->p2);
	  p.x++;
	  s->p.x = s->p.x + 64; 
	}
      s->p.y = s->p.y + 64;
      p.y++;
    }
}

void			p_i_nbr(t_s *s, int n)
{
  int			nb;
  char			c;

  s->p1.x = 10;
  s->p1.y = 5;
  nb = n % 10;
  n = n / 10;
  if (n > 0)
    p_i_nbr(s, n);
  if (nb == 0)
    {
      s->p2.x = 5;
      s->p2.y = 3;
    }
  else if (nb < 5)
    {
      s->p2.x = nb + 5;
      s->p2.y = 2;
	}
  else
    {
      s->p2.x = nb - 5;
      s->p2.y = 3;
    }
  put_img_c(s->pix, s->font, s->p, s->p1, s->p2);
  s->p.x = s->p.x + 37;
  //  put_img_c(s->pix, s->font, s->p, s->p1, s->p2);
}

void			p_i_str(t_s *s, char *str)
{
  int			i;

  i = 0;
  s->p1.x = 10;
  s->p1.y = 5;
  while (str[i] != 0)
    {
      if (str[i] < 'k')
	{
	  s->p2.x = str[i] - 97;
	  s->p2.y = 0;
	}
      else if (str[i] < 'u')
	{
	  s->p2.x = str[i] - 97 - 10;
	  s->p2.y = 1;
	}
      else
	{
	  s->p2.x = str[i] - 97 - 20;
	  s->p2.y = 2;
	}
      put_img_c(s->pix, s->font, s->p, s->p1, s->p2);
      s->p.x = s->p.x + 37;
      i++;
    }
}

void			put_img(t_bunny_pixelarray *p, t_bunny_pixelarray *i, t_bunny_position pos)
{
  t_bunny_position	pos1;
  t_bunny_position	pos2;
  unsigned int		*pix;
  unsigned int		*img;

  pix = p->pixels;
  img = i->pixels;
  pos1.y = 0;
  pos2.y = pos.y;
  while (pos1.y < i->clipable.clip_height)
    {
      pos1.x = 0;
      pos2.x = pos.x;
      while (pos1.x < i->clipable.clip_width)
	{
	  pix[(pos2.y * p->clipable.clip_width) + pos2.x] = img[(pos1.y * i->clipable.clip_width) + pos1.x];
	  pos1.x++;
	  pos2.x++;
	}
      pos1.y++;
      pos2.y++;
    }
}


t_bunny_response	key(t_bunny_event_state sta,
			    t_bunny_keysym sym, void *dat)
{
  t_s			*s;

  s = dat;
  if (sta == GO_DOWN && sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	loop(void *d)
{
  t_s			*s;

  s = d;
  fill_it(s->pix, s->color);
  s->p.x = 600;
  s->p.y = 50;
  p_i_str(s, "score");
  s->p.x = 825;
  s->p.y = 50;
  p_i_nbr(s, s->score);
  s->p.x = 500;
  s->p.y = 400;
  p_i_nbr(s, s->time);
  aff_map(s);
  bunny_blit(&s->win->buffer, &s->pix->clipable, &s->pos);
  bunny_display(s->win);
  if (s->a == 0)
    {
      s->time2 = s->time;
      s->m[rand() % 5][rand() % 5] = 3 + rand() % 3;
      s->a++;
    }
  if (s->a == 1 && s->time == s->time2 + 5)
    {
      s->a = 0;
      s->p.y = 0;
      while (s->p.y < s->t.y)
	{
	  s->p.x = 0;
	  while (s->p.x < s->t.x)
	    {
	      if (s->m[s->p.y][s->p.x] > 1)
		s->m[s->p.y][s->p.x] = 1;
	      s->p.x++;
	    }
	  s->p.y++;
	}
    }
  s->time++;
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_s	s;

  s.win = bunny_start(1000, 800, false, "guacamole");
  s.pix = bunny_new_pixelarray(1000, 800);
  s.pos.x = 0;
  s.pos.y = 0;
  s.p.x = 0;
  s.p.y = 0;
  s.p1.x = 6;
  s.p1.y = 1;
  s.p2.x = 3;
  s.p2.y = 0;
  s.img = bunny_load_pixelarray("/home/Rayan/Desktop/guacamole/GuacamoleAssets.png");
  s.font = bunny_load_pixelarray("/home/Rayan/Desktop/font.png");
  s.color.full = RED;
  s.score = 1306;
  s.vie = 3;
  s.time = 0;
  s.t.x = 4;
  s.t.y = 4;
  s.a = 0;
  s.m = init_map(s.t.x, s.t.y);
  //write(1, s.m[0], 4);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(loop);
  bunny_loop(s.win, 5, &s);
}