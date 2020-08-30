/*
** tetris.h for tetris.h in /home/Rayan/test/tetris
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Tue Feb 23 00:30:36 2016 AKKACHE Kaci
** Last update Wed Mar 23 11:07:20 2016 AKKACHE Kaci
** Last update Fri Mar 18 03:07:01 2016 AKKACHE Kaci
*/

#ifndef TETIS_H
# define TERIS_H

#include <math.h>
#include "my.h"

int		score;
int             glob;
double		lvl;

typedef struct	s_tet
{
  int	x;
  int	y;
  int	col;
  char	**t;
}		t_tet;

typedef struct	s_get
{
  char	**t;
  char	*n;
  int	len;
  int	i;
  int	l;
  int	cl;
  int	c;
}		t_get;

typedef struct	s_tab
{
  int	col;
  char	c;
}		t_tab;

typedef struct	s_t
{
  int		len;
  t_get		*g;
  t_tet		*tab_tet;
}		t_t;

typedef struct	s_hs
{
  int	s;
  char	*name;
}		t_hs;

typedef         struct s_te
{
  int		col;
  int		larg;
  int		longu;
  char		**tab_tetri;
  char		**tab_def;
  char		*tetrim;
} t_te;

typedef struct  s_opt
{
  char          **tab_opt;
  char          *left;
  char          *right;
  char          *turn;
  char          *drop;
  char          *quit;
  char          *pause;
  char          *next;
  int           level;
  char          size;
  char          *commande;
  int           map_w;
  int           map_h;
  char          *arg;
} t_opt;

//t_t	get_tab(t_te te, t_t t);

/* char		**init_tab(int tl, int tc); */
/* char		**past_tab(t_tet tet, char **t); */
/* char		**sup_line(char **t, int j); */
/* char		**check_line(char **t, int tl); */
/* void		free_tab(char **t); */
/* int		is_ok(t_tet tet, char **t, int tl); */
/* int		can_move_r(t_tet tet, char **t, int tc); */
/* int		can_move_l(t_tet tet, char **t); */

/* int		my_show_wordtab(char **tab); */
/* int		count_line(char *str, char sep); */
/* char		**str_to_wordtab(char *str, char sep); */

/* char		*str_copy3(char *dest, char *src); */
/* char		*str_copy2(char *dest, char *src); */
/* char		*str_copy(char *dest, char *src); */

/* /\* In ./read_tetri.c *\/ */
/* int    		tab_len(char **tab); */
/* char   		*my_copy_nb(char *str, int nb, int dep); */
/* int		check_larg(t_te *te); */
/* int		check_taille2(t_te *te, char *str); */
/* int		check_taille(char *str); */
/* int    		check_error(char *str); */
/* char   		*open_file(char *file, char *str, t_te *te); */
/* char   		*open_directory(char *file); */
/* int		read_tet(t_te *te); */
/* /\* In ./read_tetri2.c *\/ */
/* int    		check_larg(t_te *te); */
/* char   		*my_copy_nb(char *str, int nb, int dep); */


/* /\* In ./check.c *\/ */
/* int			is_ok(t_tet tet, char **t, int tl); */
/* int			can_move_r(t_tet tet, char **t, int tc); */
/* int			can_move_l(t_tet tet, char **t); */
/* /\* In ./read_tetri.c *\/ */
/* int			tab_len(char **tab); */
/* int			check_error(char *str); */
/* char			*open_file(char *file, char *str, t_te *te); */
/* char			*open_directory(char *file); */
/* int			read_tet(t_te *te); */
/* /\* In ./get_tab.c *\/ */
/* t_get			get_w(char *b, t_get g); */
/* t_get			get_h(char *b, t_get g); */
/* t_get			get_c(char *b, t_get g); */
/* char			*cut_s(char *s); */
/* char			*get_tab2(char *t, t_get g); */
/* int			check_tet(t_get g); */
/* int			is_sup(char *s1, char *s2); */
/* t_get			*tri_g(t_get *g); */
/* t_tet			*add_tet(t_tet *t1, t_tet tet, int len); */
/* t_t			get_tab(t_te te, t_t t); */
/* //t_get			*get_tab(t_te t, t_get *g); */
/* /\* In ./read_tetri2.c *\/ */
/* int			check_larg(t_te *te); */
/* char			*my_copy_nb(char *str, int nb, int dep); */
/* int			check_taille2(t_te *te, char *str); */
/* int			check_taille(char *str); */
/* /\* In ./str_to_wordtab.c *\/ */
/* int			my_show_wordtab(char **tab); */
/* int			count_line(char *str, char sep); */
/* char			**str_to_wordtab(char *str, char sep); */
/* /\* In ./tetris.c *\/ */
/* t_tet			init_tet(t_tet *tab, int max); */
/* void			aff(char **t); */
/* void			aff_gui(char **t, int s); */
/* void			aff_tet(t_tet tet); */
/* t_tet			rotate(t_tet tet, char **tab, int tl, int tc); */
/* WINDOW			*init(WINDOW *scr); */
/* int			game_over(char **t, t_tet tet, int len, WINDOW *scr); */
/* t_hs			*init_hs(t_hs *hs); */
/* /\* In ./tab.c *\/ */
/* char			**init_tab(int tl, int tc); */
/* char			**past_tab(t_tet tet, char **t); */
/* char			**sup_line(char **t, int j); */
/* char			**check_line(char **t, int tl); */
/* void			free_tab(char **t); */
/* /\* In ./str_cat.c *\/ */
/* char			*str_copy2(char *dest, char *src); */
/* char			*str_copy(char *dest, char *src); */
/* char			*str_copy3(char *dest, char *src); */
/* /\* In ./debug/gestion_av.c *\/ */
/* char			**copy_tableau(char **tab2); */
/* char			**look_for_d(char **av); */
/* int			clear_commande(t_opt *opt); */
/* int			check_av(char **tab); */
/* /\* In ./debug/option2.c *\/ */
/* int			options(char *str, t_opt *opt, char **av); */
/* int			show_help(t_opt *opt,char **av); */
/* /\* In ./debug/option3.c *\/ */
/* void			change_oa(char *str); */
/* int			key_quit(t_opt *opt); */
/* int			key_pause(t_opt *opt); */
/* int			hide_next(t_opt *opt); */
/* int			map_size(t_opt *opt); */
/* int			debug(t_opt *opt); */
/* /\* In ./debug/option4.c *\/ */
/* int			start_level(t_opt *opt); */
/* int			my_key_left(t_opt *opt); */
/* int			my_key_right(t_opt *opt); */
/* int			key_turn(t_opt *opt); */
/* int			key_drop(t_opt *opt); */
/* int			set_opt(t_opt *opt); */
/* /\* In ./debug/option.c *\/ */
/* void			check_opt(t_opt *opt); */
/* int			function_op(t_opt *opt); */
/* int			point_opt(t_opt *opt); */
/* int			parse_opt(char *str, t_opt *opt); */
/* int			gestion_opt(int ac, char **av, t_opt *opt); */
/* /\* In ./debug/canon.c *\/ */
/* char			*verif_env(char **env); */
/* int			mode_canon(int n); */

/* /\* In ./debug/str_to_wordtab.c *\/ */
/* int			my_show_wordtab(char **tab); */
/* int			count_line(char *str, char sep); */
/* char			**str_to_wordtab(char *str, char sep); */
/* /\* In ./debug/.#gestion_av.c *\/ */
/* /\* In ./debug/str_cat.c *\/ */
/* char			*str_copy2(char *dest, char *src); */
/* char			*str_copy(char *dest, char *src); */
/* char			*str_copy3(char *dest, char *src); */
/* /\* In ./lib/my_put_nbr.c *\/ */
/* int			aff_my_put_nbr(va_list ap); */
/* int			my_put_nbr(int nb); */
/* /\* In ./lib/autres.c *\/ */
/* int			aff_my_put_nbr_basep(va_list ap); */
/* /\* In ./lib/my_strcmp.c *\/ */
/* int			my_strcmp(const char *s1, const char *s2); */
/* int			my_strncmp(const char *s1, const char *s2, int nb); */
/* /\* In ./lib/my_put_nbrbase.c *\/ */
/* int			aff_my_put_nbr_base(va_list ap); */
/* int			aff_my_put_nbr_BASE(va_list ap); */
/* int			my_put_nbr_base(int nb); */
/* int			my_put_nbr_BASE(int nb); */
/* int			my_put_nbr_basep(long nb); */
/* /\* In ./lib/my_put_nbroctal.c *\/ */
/* int			aff_convert_oct(va_list ap); */
/* int			aff_convert_bin(va_list ap); */
/* int			my_put_moins(int nb); */
/* int			convert_oct(int nb); */
/* int			convert_bin(int nb); */
/* /\* In ./lib/modulo.c *\/ */
/* int			aff_modulo(va_list ap); */
/* int			modulo(int c); */
/* /\* In ./lib/my_revstr.c *\/ */
/* char			*my_revstr(char *str); */
/* /\* In ./lib/my_static.c *\/ */
/* int			my_return(int nb); */
/* int			calc(va_list ap); */
/* /\* In ./lib/my_strcpy.c *\/ */
/* char			*my_strcpy(char *dest, char *src); */
/* /\* In ./lib/my_put_nbru.c *\/ */
/* int			aff_my_put_nbru(va_list ap); */
/* int			my_put_nbru(unsigned int nb); */
/* /\* In ./lib/my_putchar.c *\/ */
/* int			aff_my_putchar(va_list ap); */
/* int			my_putchar(int c); */
/* /\* In ./lib/my_putStr.c *\/ */
/* int			my_affstr(va_list ap); */
/* int			my_putstr(char *str); */
/* /\* In ./lib/my_printf.c *\/ */
/* int			check_char(char c); */
/* void			check_aff(int i, va_list ap); */
/* int			conditions(const char *str, va_list ap, int i); */
/* int			my_printf(const char *str, ...); */
/* /\* In ./lib/my_getnbr.c *\/ */
/* int			my_getnbr(char *str); */

int			have_ptet(char *s, int i);

/* In ./my_get_nbr.c */
int			error_input(char *str);
int			my_get_nbr(char *str);
/* In ./check.c */
int			is_ok(t_tet tet, char **t, int tl);
int			can_move_r(t_tet tet, char **t, int tc);
int			can_move_l(t_tet tet, char **t);
/* In ./read_tetri.c */
int			tab_len(char **tab);
int			check_error(char *str);
char			*open_file(char *file, char *str, t_te *te);
char			*open_directory(char *file);
int			read_tet(t_te *te);
/* In ./get_tab.c */
t_get			get_w(char *b, t_get g);
t_get			get_h(char *b, t_get g);
t_get			get_c(char *b, t_get g);
char			*cut_s(char *s);
char			**get_tab2(char *t, t_get g);
int			check_tet(t_get g, char *s);
int			is_sup(char *s1, char *s2);
t_get			*tri_g(t_get *g);
t_tet			*add_tet(t_tet *t1, t_tet tet, int len);
t_t			get_tab(t_te te, t_t t);
/* In ./read_tetri2.c */
int			check_larg(t_te *te);
char			*my_copy_nb(char *str, int nb, int dep);
int			check_taille2(t_te *te, char *str);
int			check_taille(char *str);
/* In ./str_to_wordtab.c */
int			my_show_wordtab(char **tab);
int			count_line(char *str, char sep);
char			**str_to_wordtab(char *str, char sep);
/* In ./tetris.c */
t_tet			init_tet(t_tet *tab, int max);
void			aff(char **t);
void			aff_gui(char **t, int s, int c);
void			aff_tet(t_tet tet);
t_tet			rotate(t_tet tet, char **tab, int tl, int tc);
WINDOW			*init(WINDOW *scr);
int			game_over(char **t, t_tet tet, int len, WINDOW *scr);
t_hs			*init_hs(t_hs *hs);
/* In ./tab.c */
char			**init_tab(int tl, int tc);
char			**past_tab(t_tet tet, char **t);
char			**sup_line(char **t, int j);
char			**check_line(char **t, int tl, char **t2, int s, int c);
void			free_tab(char **t);
/* In ./main.c */
int			main(int ac, char **av, char **env);
/* In ./str_cat.c */
char			*str_copy2(char *dest, char *src);
char			*str_copy(char *dest, char *src);
char			*str_copy3(char *dest, char *src);
/* In ./debug/gestion_av.c */
int			check_d(char **av);
char			**copy_tableau(char **tab2);
char			**look_for_d(char **av);
int			clear_commande(t_opt *opt);
int			check_av(char **tab);
/* In ./debug/option2.c */
int			check_help(char **av, t_opt *opt);
int			options(char *str, t_opt *opt, char **av);
int			show_help(t_opt *opt, char **av);
/* In ./debug/option3.c */
void			change_oa(char *str);
int			key_quit(t_opt *opt);
int			key_pause(t_opt *opt);
int			hide_next(t_opt *opt);
int			debug2(t_opt *opt);
int			debug(t_opt *opt);
int			map_size(t_opt *opt);
/* In ./debug/option4.c */
int			start_level(t_opt *opt);
int			my_key_left(t_opt *opt);
int			my_key_right(t_opt *opt);
int			key_turn(t_opt *opt);
int			key_drop(t_opt *opt);
int			set_opt(t_opt *opt);
/* In ./debug/option.c */
void			check_opt(t_opt *opt);
int			function_op(t_opt *opt);
int			point_opt(t_opt *opt);
int			parse_opt2(char *str, t_opt *opt);
int			parse_opt(char *str, t_opt *opt);
int			gestion_opt(int ac, char **av, t_opt *opt);
/* In ./debug/canon.c */
char			*verif_env(char **env);
int			mode_canon(int n);
/* In ./debug/str_to_wordtab.c */
int			my_show_wordtab(char **tab);
int			count_line(char *str, char sep);
char			**str_to_wordtab(char *str, char sep);
/* In ./debug/str_cat.c */
char			*str_copy2(char *dest, char *src);
char			*str_copy(char *dest, char *src);
char			*str_copy3(char *dest, char *src);
/* In ./lib/my_put_nbr.c */
int			aff_my_put_nbr(va_list ap);
int			my_put_nbr(int nb);
/* In ./lib/my_strcmp.c */
int			my_strcmp(const char *s1, const char *s2);
int			my_strncmp(const char *s1, const char *s2, int nb);
/* In ./lib/my_put_nbrbase.c */
int			aff_my_put_nbr_base(va_list ap);
int			aff_my_put_nbr_BASE(va_list ap);
int			my_put_nbr_base(int nb);
int			my_put_nbr_BASE(int nb);
int			my_put_nbr_basep(long nb);
/* In ./lib/my_put_nbroctal.c */
int			aff_convert_oct(va_list ap);
int			aff_convert_bin(va_list ap);
int			my_put_moins(int nb);
int			convert_oct(int nb);
int			convert_bin(int nb);
/* In ./lib/my_revstr.c */
char			*my_revstr(char *str);
/* In ./lib/my_static.c */
int			my_return(int nb);
int			calc(va_list ap);
/* In ./lib/my_strcpy.c */
char			*my_strcpy(char *dest, char *src);
/* In ./lib/my_put_nbru.c */
int			aff_my_put_nbru(va_list ap);
int			my_put_nbru(unsigned int nb);
/* In ./lib/my_putchar.c */
int			aff_my_putchar(va_list ap);
int			my_putchar(int c);
/* In ./lib/my_putStr.c */
int			my_affstr(va_list ap);
int			my_putstr(char *str);
/* In ./lib/my_printf.c */
int			check_char(char c);
void			check_aff(int i, va_list ap);
int			conditions(const char *str, va_list ap, int i);
int			my_printf(const char *str, ...);
/* In ./lib/my_getnbr.c */
int			my_getnbr(char *str);

#endif
