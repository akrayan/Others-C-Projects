/*
** my2.h for  in /home/axel/rendu/PSU/tetris_dossier/PSU_2015_tetris/debug
**
** Made by Axel Proust
** Login   <proust_c@epitech.net>
**
** Started on  Wed Mar 16 10:47:32 2016 Axel Proust
** Last update Thu Mar 17 14:52:42 2016 Axel Proust
*/

#ifndef MY2_H_
# define MY2_H_

#include "./my.h"

/* In ./option2.c */
int			options(char *str, t_opt *opt);
int			show_help(t_opt *opt);
/* In ./option3.c */
int			key_quit(t_opt *opt);
int			key_pause(t_opt *opt);
int			hide_next(t_opt *opt);
int			debug(t_opt *opt);
int			map_size(t_opt *opt);
/* In ./option4.c */
int			start_level(t_opt *opt);
int			key_left(t_opt *opt);
int			key_right(t_opt *opt);
int			key_turn(t_opt *opt);
int			key_drop(t_opt *opt);
int			set_opt(t_opt *opt);
/* In ./option.c */
void			check_opt(t_opt *opt);
int			function_op(t_opt *opt);
int			point_opt(t_opt *opt);
void			parse_opt(char *str, t_opt *opt);
int			main(int ac, char **av);

#endif /* !MY_H_ */
