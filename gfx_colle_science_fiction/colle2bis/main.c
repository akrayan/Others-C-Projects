/*
** main.c for main.c in /home/thenascrazy/Inforgraphie/rush/gfx_colle_science_fiction/colle1
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**pos1.x = pos1.x + 4;
	  pos2.x = pos2.x + 4;
** Started on  Wed May 18 18:11:55 2016 Afou Nacerdine
** Last update Wed May 18 19:56:34 2016 AKKACHE Kaci
*/

#include "colle.h"

void			put_img(t_bunny_pixelarray *p, t_bunny_pixelarray *i,
				t_bunny_position pos)
{
  t_bunny_position      pos1;
  t_bunny_position      pos2;
  unsigned char         *pix;
  unsigned char         *img;

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
	  if (img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4] > 0 && img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4 + 1] > 0
	      && img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4 + 2] > 0 && img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4 + 3] > 0)
	    {
	      pix[((pos2.y * p->clipable.clip_width) + pos2.x) * 4] = img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4];
	      pix[((pos2.y * p->clipable.clip_width) + pos2.x) * 4 + 1] = img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4 + 1];
	      pix[((pos2.y * p->clipable.clip_width) + pos2.x) * 4 + 2] = img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4 + 2];
	      pix[((pos2.y * p->clipable.clip_width) + pos2.x) * 4 + 3] = img[((pos1.y * i->clipable.clip_width) + pos1.x) * 4 + 3];
	    }
	  pos1.x++;
	  pos2.x++;
        }
      pos1.y++;
      pos2.y++;
    }
}

void                    fill_it(t_bunny_pixelarray *p, t_color c)
{
  int                   i;
  unsigned char         *pix;

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


t_bunny_response        key(t_bunny_event_state sta,
                            t_bunny_keysym sym, void *d)
{
  t_s			*s;

  s = d;
  if (sta == GO_DOWN && sym == BKS_ESCAPE)
    {
      if (s->t == -1)
	write(1, "1", 1);
      return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_bunny_response        loop(void *d)
{
  t_s                   *s;
  int			i;

  s = d;
  if (s->vrai == 0)
    {
      bunny_sound_play(&s->m->sound);
      s->vrai++;
    }
  put_img(s->pix, s->fond, s->p1);
  if (s->v2 == 0)
    {
      s->color.full = BLUE;
      s->a = 0;
      while (s->a < 360)
	{
	  s->p2.x = 610 + cos(s->a) * (s->t2);
	  s->p2.y = 300 + sin(s->a) * (s->t2);
	  tekpixel(s->pix, &s->p2, &s->color);
	  s->a++;
	}
      if (s->t2 >= 0)
	s->t2--;
      else
	s->v2 = 1;
      bunny_blit(&s->win->buffer, &s->pix->clipable, &s->pos);
      bunny_display(s->win);
    }
  else 
    {
      s->color.full = BLACK;
      fill_it(s->pix, s->color);
      put_img(s->pix, s->fond, s->p1);
      s->color.full = BLUE;
      s->t2 = 250;
      while (s->t2 >= 0)
	{
	  s->a = 0;
	  while (s->a < 360)
	    {
	      s->p2.x = 610 + cos(s->a) * (s->t2);
	      s->p2.y = 300 + sin(s->a) * (s->t2);
	      tekpixel(s->pix, &s->p2, &s->color);
	      s->a++;
	    }
	  s->t2--;
	}
      s->color.full = BLACK;
      s->a = 0;
      while (s->a < 360)
	{
	  i = 0;
	  while (i < 20)
	    {
	      s->p2.x = 610 + cos(s->a) * (s->t + i);
	      s->p2.y = 300 + sin(s->a) * (s->t + i);
	      tekpixel(s->pix, &s->p2, &s->color);
	      i++;
	    }
	  s->a++;
	}
      bunny_blit(&s->win->buffer, &s->pix->clipable, &s->pos);
      bunny_display(s->win);
      if (s->t < 225)
	s->t++;
      else
	s->t = 0;
    }
  return (GO_ON);
}

int	main()
{
  t_s	s;

  s.win = bunny_start(1420, 597, false, "quantum");
  s.pix = bunny_new_pixelarray(1420, 597);
  s.fond = bunny_load_pixelarray("stargate.png");
  s.m = bunny_load_music("stargate.ogg");
  s.color.full = BLACK;
  fill_it(s.pix, s.color);
  s.pos.x = 0;
  s.pos.y = 0;
  s.p1.x = 310;
  s.p1.y = 0;
  s.p2.x = 0;
  s.p2.y = 0;
  s.vrai = 0;
  s.t = 0;
  s.t2 = 225;
  s.v2 = 0;
  bunny_set_key_response(key);
  bunny_set_loop_main_function(loop);
  bunny_loop(s.win, 150, &s);
  return (0);
}
