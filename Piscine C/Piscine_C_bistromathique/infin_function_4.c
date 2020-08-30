/*
** infin_div.c for  in /home/zemmou_b/rendu/bistro
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Fri Oct 30 12:00:26 2015 Billal Zemmouri
** Last update Tue Nov  3 22:01:06 2015 Afou Nacerdine
*/
#include <stdlib.h>
#include "./include/my.h"
#include "./include/bistromatique.h"

t_list_div	infin_divcal_stock(char *nb1, char *nb2, t_list_div div)
{
  div.i = 0;
  div.result = malloc(sizeof(char) * (my_strlen(div.tmp1) + 1));
  div.result = dumpdiv(div.tmp1, div.b, div.y);
  while (infin_sub(div.result, nb2)[0] >= '0')
    {
      if (infin_sub(div.result, nb2)[0] >= '0')
	{
	  div.result = infin_sub(div.result, nb2);
	  div.i = div.i + 1;
	}
    }
  div.resultf[div.a] = div.i + 48;
  div.tmp1 = rest(div.result, nb1, div.y,my_strlen(nb1));
  div.tmp1 = addz(div.tmp1,nb1);
  if (infin_sub(div.result, nb2)[0] >= '0')
    div.b = div.b + 1;
  div.a = div.a + 1;
  div.y = div.y + 1;
  return (div);
}

char	*infin_divcal(char *nb1, char *nb2)
{
  t_list_div	div;

  div.i = 0;
  div.y = 1;
  div.a = 0;
  div.b = 0;
  div.resultf = malloc(sizeof(char) * (my_strlen(nb1) + 1));
  div.result = malloc(sizeof(char) * (my_strlen(nb1) + 2));
  div.tmp1 = dump(nb1,my_strlen(nb1));
  while (div.y < my_strlen(nb1) + 1)
    div = infin_divcal_stock(nb1, nb2, div);
  div.resultf[div.a] = 0;
  return (div.resultf);
}

t_list_mod	infin_modulocal_stock(char *nb1, char *nb2, t_list_mod mod)
{
  mod.i = 0;
  mod.result = malloc(sizeof(char) * (my_strlen(mod.tmp1) + 1));
  mod.result = dumpdiv(mod.tmp1, mod.b, mod.y);
  while (infin_sub(mod.result, nb2)[0] >= '0')
    {
      if (infin_sub(mod.result, nb2)[0] >= '0')
	{
	  mod.result = infin_sub(mod.result, nb2);
	  mod.i = mod.i + 1;
	}
    }
  mod.resultf[mod.a] = mod.i + 48;
  mod.tmp1 = rest(mod.result, nb1, mod.y, my_strlen(nb1));
  mod.tmp1 = addz(mod.tmp1,nb1);
  if (infin_sub(mod.result, nb2)[0] >= '0')
    mod.b = mod.b + 1;
  mod.a = mod.a + 1;
  mod.y = mod.y + 1;
  return (mod);
}

char	*infin_modulocal(char *nb1, char *nb2)
{
  t_list_mod	mod;

  mod.y = 1;
  mod.a = 0;
  mod.b = 0;
  mod.resultf = malloc(sizeof(char) * (my_strlen(nb1) + 1));
  mod.result = malloc(sizeof(char) * (my_strlen(nb1) + 2));
  mod.tmp1 = dump(nb1,my_strlen(nb1));
  while (mod.y < my_strlen(nb1) + 1)
    mod = infin_modulocal_stock(nb1, nb2, mod);
  mod.resultf[mod.a] = 0;
  return (mod.tmp1);
}
