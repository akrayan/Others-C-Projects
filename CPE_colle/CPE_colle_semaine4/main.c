/*
** main.c for main.c in /home/Rayan/Colle/CPE_colle_semaine4
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Tue May 17 18:42:29 2016 AKKACHE Kaci
** Last update Tue May 17 22:17:37 2016 VELLA CYRIL
*/

#include	"./include/poke.h"

int		main(int ac, char **av)
{
  t_l			*l;
  t_poke		p1;
  t_poke		p2;

   p1.name = "carapute";
  p1.atk = 100;
  p1.def = 200;
  p1.vie = 600;
  p1.vit = 150;

  p2.name = "tortenkule";
  p2.atk = 10000;
  p2.def = 200;
  p2.vie = 600;
  p2.vit = 150;
  fight(p1, p2);
  
  srand(time(NULL));
  l = NULL;

}

int		aff1(t_poke p1, t_poke p2, t_fight f)
{
  t_fight		e;
  
  e.a = my_putstr(p1.name);
  e.a = my_putstr(" attacks for ");
  e.b = my_putnbr(f.a);
  e.a = my_putstr(" damage\n");
  e.a = my_putstr(p2.name);
  e.a = my_putstr(" blocks ");
  e.b = my_putnbr(f.b);
  e.a = my_putstr(" damage\n");
  e.a = my_putstr(p2.name);
  e.a = my_putstr(" loses ");
  e.b = my_putnbr(f.l);
  e.a = my_putstr(" health ");
  e.b = my_putnbr(p2.vie);
  e.a = my_putstr(" left)\n\n");
  if (e.a < 0 || e.b < 0)
    return (-1);
}

int		aff2(t_poke p1, t_poke p2, t_fight f)
{
  t_fight		i;
  
  i.a = my_putstr(p2.name);
  i.a = my_putstr(" attacks for ");
  i.b = my_putnbr(f.a);
  i.a = my_putstr(" damage\n");
  i.a = my_putstr(p1.name);
  i.a = my_putstr(" blocks ");
  i.b = my_putnbr(f.b);
  i.a = my_putstr(" damage\n");
  i.a = my_putstr(p1.name);
  i.a = my_putstr(" loses ");
  i.b = my_putnbr(f.l);
  i.a = my_putstr(" health (");
  i.b = my_putnbr(p1.vie);
  i.a = my_putstr(" left)\n\n");
  if (i.a < 0 || i.b < 0)
    return (-1);
}

void		fight(t_poke p1, t_poke p2)
{
  t_fight	f;

  while (p1.vie > 0 && p2.vie > 0)
    {
      f.a = rand() % (p1.atk + 1);
      f.b = rand() % (p2.def + 1);
      f.l = f.a - f.b;
      if (f.b > f.a)
	f.l = 0;
      p2.vie = p2.vie - f.l;
      aff1(p1, p2, f);
      if (p2.vie > 0)
	{
	  f.a = rand() % (p2.atk + 1);
	  f.b = rand() % (p1.def + 1);
	  f.l = f.a - f.b;
	  if (f.b > f.a)
	    f.l = 0;
	  p1.vie = p1.vie - f.l;
	  aff2(p1, p2, f);	  
	}
    }
  live(p1, p2);
}

int		live(t_poke p1, t_poke p2)
{
  int		i;

  if (p1.vie > 0)
    {
      i = my_putstr(p2.name);
      i = my_putstr(" is KO\n");
      i = my_putstr(p1.name);
      i = my_putstr(" wins the fight\n");
      return (0);
    }
  else
    {
     i = my_putstr(p1.name);
     i = my_putstr(" is KO\n");
     i = my_putstr(p2.name);
     i = my_putstr(" wins the fight\n");
     return (0);
    }
  if (i < 0)
    return (-1);
}
