/*
** bistro.h for bistro.h in /home/afou_n/rendu/Piscine_C_evalexpr/include
** 
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
** 
** Started on  Mon Oct 26 20:04:16 2015 Afou Nacerdine
** Last update Tue Nov  3 18:52:35 2015 AKKACHE Kaci
*/

#ifndef LIST_H_
#define LIST_H_
typedef struct s_list_param
{
  char *str1;
  char  *str2;
  int i;
}t_list_param;

typedef struct s_list_sub
{
  char  *s1cpy;
  char  *s2cpy;
  char  *s3;
  int   n;
  int   size;
}t_list_sub;

typedef struct s_list_mult
{
  int   size;
  int   i;
  int   y;
  int   a;
  char  **tab;
  int   ret;
}t_list_mult;

typedef struct s_list_div
{
  int   i;
  int   y;
  int   a;
  int   b;
  char *tmp1;
  char  *result;
  char  *resultf;
}t_list_div;

typedef struct s_list_mod
{
  int   i;
  int   y;
  int   a;
  int   b;
  char *tmp1;
  char  *result;
  char  *resultf;
}t_list_mod;

typedef struct s_list_init
{
  char  **mul;
  char  **div;
  char	**mod;
  int   j;
  int   nb;
}t_list_init;
#endif
#define SYNTAXE_ERROR_MSG (my_putstr("syntax error"))

char	*infin_add(char *s1, char *s2);
char	*my_deletez(char *str);
int	checkparams(char *s1, char *s2);
char	*my_revcopy(char *str, int size);
char	*infin_mult(char *s1, char *s2);
char    *infin_addpositiv(char *s1 ,char *s2);
char    *infin_addneg(char *s1 ,char *s2);
char	*infin_sub(char *s1, char *s2);
char    *infin_doubleneg(char *s1 ,char *s2);
char    **infin_mult1(char *nb1, char *nb2 ,int strlen);
char	*sum(char **tab, int size);
char	*infin_div(char*nb1, char *nb2);
char	*infin_modulo(char*nb1, char *nb2);
char	*my_copy(char *str);
char	*dump(char *str,int z);
char    *rest(char*rest ,char *nb1, int begin ,int z);
char	*dumpdiv(char *str,int begin,int end);
char	*addz(char *str ,char * nb1);
char	*infin_divcal(char *nb1, char *nb2);
char	*infin_modulocal(char *nb1, char *nb2);
char    *par(char **str2, int i);
int     tablen(char **tab);
char    *tabsum(char **sum);
char    *domul(char **mul);
char    *dodiv(char **div);
char    *domod(char **mod);
int     nbmul(char **str2, int i);
int     nbdiv(char **str2, int i);
int     nbmod(char **str2, int i);
int     geti(char **str2, int i);
int     geti2(char **str2, int i);
int     geti3(char **str2, int i);
char    **getsum(char **sum, char **str2, int i, int s);
char    **getstr2(char **sum, char **str2, int i, int s);
char    **finishsum(char **sum, char **str2, int i, int s);
char    **initmul(char **str2, char **sum, int s, int i);
char    **initdiv(char **str2, char **sum, int s, int i);
char    **initmod(char **str2, char **sum, int s, int i);
int     syntax_error(char *str);
char	*convert_base_to_nb(char *nbbase, char *base);
char	**convertab(char **str2, char *b);
char	*int_to_char(int nb);
