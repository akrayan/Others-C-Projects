/*
** rt.h for rt.h in /home/Rayan/Info/gfx_raytracer1
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Sat Mar  5 13:41:56 2016 AKKACHE Kaci
** Last update Tue May 24 13:57:13 2016 AKKACHE Kaci
*/

#ifndef RT_H_
 #define RT_H_

#include <lapin.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "liblap.h"
#include "../file_scene/my.h"

typedef	struct		s_c
{
  double	       	a;
  double	       	b;
  double	       	c;
  double	       	d;
  double	       	t1;
  double	       	t2;
}			t_c;

typedef	struct		s_co
{
  int			i;
  int			j;
  int			k;
  double		*d;
  double		x_;
  double		y_;
  double		z_;
  double		x;
  double		y;
  double		z;
  double		nx;
  double		ny;
  double		nz;
  double		lx;
  double		ly;
  double		lz;  
  double		cosa;
  t_color		color;
  t_color		c;
}			t_co;

typedef	struct		s_obj
{
  struct s_l		*o;
  t_bunny_pixelarray	*t;
  unsigned char		*p;
  int			s;
  double		x;
  double		y;
  double       		z;
  double		lx;
  double		ly;
  double		lz;
  char			type;
  char			l;
  double       		r;
  int			i;
  t_color		c;
  double		a;
  double		b;
}			t_obj;

typedef	struct		s_lum
{
  double		x;
  double		y;
  double       		z;
  t_color		c;
  double		p;
  int			i;
  char			**tab;
}			t_lum;

typedef	struct		s_l
{
  struct s_l		*next;
  struct s_l		*last;

  t_obj			*obj;
  t_lum			*lum;
}			t_l;

typedef	struct		s_s
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_position	p;
  t_color		color;
  t_l			*l_obj;
  t_l			*l_lum;
  double       		*k;
  double		cx;
  double		cy;
  double		cz;
  double		ox;
  double		oy;
  double		oz;
  double		vx;
  double		vy;
  double		vz;
  double		rx;
  double		ry;
  double		rz;
}			t_s;

/* !FILE_SCENE */
void            make_cmp(t_s *s, t_obj *o, t_obj *p, t_lum *l);
void            make_cmp_bis(t_s *s, t_obj *o, t_obj *p, t_lum *l);
void            make_cmp_rebis(t_s *s, t_obj *o, t_obj *p, t_lum *l);
char            *get_value(char *str);
char            *read_file(char *filename);
char            *epur_str(char *str);
char            **my_str_to_wordtab(char *str, char sep);
char            *my_strdup(char *str);
unsigned int    cmp_color(char *str);

t_bunny_pixelarray	*d_pix(t_bunny_pixelarray *p1);
int	list_len(t_l *l);
t_obj	*dup_obj(t_obj *obj);
t_lum	*dup_lum(t_lum *lum);
t_l	*add_elem(t_l *l, t_obj *obj, t_lum *lum);
t_l	*sup_elem(t_l *l);
t_l	*sup_elem_id(t_l *l, int i);

double			calc_s(t_s *s, t_l *p);
t_c			calc_pa_1(t_s *s, t_l *p, t_c c);
double			calc_pa(t_s *s, t_l *p);
double			calc_cy_x(t_s *s, t_obj *obj);
double			calc_cy_y(t_s *s, t_obj *obj);
double			calc_cy_z(t_s *s, t_obj *obj);
void			t_r(t_s *s, t_bunny_position pos);
void			rot(t_s *s);
double			calc_p(t_s *s, t_obj *obj);
double			calc_oc(t_s *s, t_obj *o);
double			calc_cy_0(t_s *s, t_l *p);
double			*calc_main(t_s *s, t_l *l);
t_co			color_s_1(t_co c, t_s *s, double k);
t_co			color_s_2(t_co c, t_obj *obj);
t_co			color_s_3(t_co c, t_s *s, t_obj *obj);
t_color			color_s(t_s *s, t_obj *obj, double k);
t_co			color_cy_1(t_co c, t_s *s, t_obj *obj, double k);
t_co			color_cy_2(t_co c, t_s *s, t_obj *obj, double k);
t_co			color_cy_3(t_co c, t_s *s, t_obj *obj);
t_color			color_cy(t_s *s, t_obj *obj, double k);
t_co			color_p_1(t_co c, t_obj *obj);
t_co			color_p_2(t_co c, t_s *s);
t_color			color_p(t_s *s, t_obj *obj, double k);
t_color			color(t_s *s, t_obj *obj, double k);
int			g_c_1(double *k, t_l *l);
t_color			g_color(t_s *s, t_l *l);
void			rt(t_s *s);

#endif
