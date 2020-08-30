/*
** tetris.c for tetris.c in /home/Rayan/test
**
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
**
** Started on  Mon Feb 22 14:52:06 2016 AKKACHE Kaci
** Last update Wed Mar 23 11:10:16 2016 AKKACHE Kaci
** Last update Fri Mar 18 03:32:26 2016 AKKACHE Kaci
*/

#include "./tetris.h"

t_tet		init_tet(t_tet *tab, int max)
{
  int		i;
  int		j;
  int		k;
  t_tet		tet;

  k = (rand() % max);
   tet.col = tab[k].col;
   if ((tet.t = malloc(sizeof(char *) * (tab_len(tab[k].t) + 1))) == NULL)
     return ;
  j = 0;
  while (j < tab_len(tab[k].t))
    {
      i = -1;
      if ((tet.t[j] = malloc(my_strlen(tab[k].t[0]) + 1)) == NULL)
	return ;
      while (++i < my_strlen(tab[k].t[0]))
	tet.t[j][i] = tab[k].t[j][i];
      tet.t[j][i] = '\0';
      j++;
    }
    tet.t[j] = NULL;
  tet.x = 4;
  tet.y = 0;
  return (tet);
}

void		aff(char **t)
{
  int		i;
  int		j;

  j = 0;
  while (j < tab_len(t) + 2)
    {
      i = 0;
      while (i < (my_strlen(t[0]) * 2) + 2)
	{
	  if ((j == 0 && i == 0) || (j == tab_len(t) + 1 && i == (my_strlen(t[0]) * 2) + 1))
	    mvprintw(j + 7, i, "/");
	  else if ((j == tab_len(t) + 1  && i == 0) || (j == 0 && i == (my_strlen(t[0]) * 2) + 1))
	    mvprintw(j + 7, i, "\\");
	  else if (j == 0 || j == tab_len(t) + 1)
	    mvprintw(j + 7, i, "-");
	  else if (i == 0 || i == (my_strlen(t[0]) * 2) + 1)
	    mvprintw(j + 7, i, "|");
	  i++;
	}
      j++;
    }
  j = 0;
  while (t[j] != NULL)
    {
      i = 0;
      while (t[j][i] != '\0')
	{
	  if (t[j][i] > 0)
	    {
	      attron(COLOR_PAIR(t[j][i]));
	      mvprintw(j + 8, (i * 2) + 1, "**");
	      attroff(COLOR_PAIR(t[j][i]));
	    }
	  i++;
	}
      j++;
    }
  refresh();
}

void		aff_gui(char **t, int s, int col)
{
  int		i;
  int		j;
  int		m;
  int		h;

  j = 0;
  while (j < tab_len(t) + 2)
    {
      i = 0;
      while (i < (my_strlen(t[0]) * 2) + 2)
	{
	  if ((j == 0 && i == 0) || (j == tab_len(t) + 1 && i == (my_strlen(t[0]) * 2) + 1))
	    mvprintw(j + 6 + 7, 22 + i, "/");
	  else if ((j == tab_len(t) + 1  && i == 0) || (j == 0 && i == (my_strlen(t[0]) * 2) + 1))
	    mvprintw(j + 6 + 7, 22 + i, "\\");
	  else if (j == 0 || j == tab_len(t) + 1)
	    mvprintw(j + 6 + 7, 22 + i, "-");
	  else if (i == 0 || i == (my_strlen(t[0]) * 2) + 1)
	    mvprintw(j + 6 + 7, 22 + i, "|");
	  i++;
	}
      j++;
    }
  j = 0;
  while (t[j] != NULL)
    {
      i = 0;
      while (t[j][i] != '\0')
	{
	  if (col > 0 && t[j][i] == '*')
	    {
	      attron(COLOR_PAIR(col));
	      mvprintw(j + 7 + 7, (i * 2) + 23, "**");
	      attroff(COLOR_PAIR(col));
	    }
	  i++;
  	}
      j++;
    }
  refresh();
  j = 0;
  /*while (t[j] != NULL)
    {
      mvprintw(j + 7 + 7, 23, t[j]);
      
      j++;
      }*/
  m = s / 60;
  s = s % 60;
  h = m / 60;
  m = m % 60;
  mvprintw(4 + 7, 22, "time : %dh %dm %ds", h, m, s);
  mvprintw(3 + 7, 22, "level : %d", (int)lvl + 1);
  mvprintw(2 + 7, 22, "score : %d", score);
  refresh();
}

void		aff_tet(t_tet tet)
{
  int		i;
  int		j;

  j = 0;
  while (tet.t[j] != NULL)
    {
      i = 0;
      while (tet.t[j][i] != '\0')
	{
	  if (tet.col > 0 && tet.t[j][i] == '*')
	    {
	      attron(COLOR_PAIR(tet.col));
	      mvprintw(j + tet.y + 8, (i * 2) + (tet.x * 2) + 1, "**");
	      attroff(COLOR_PAIR(tet.col));
	    }
	  i++;
  	}
      j++;
    }
  refresh();
}

t_tet		rotate(t_tet tet, char **tab, int tl, int tc)
{
  int		i;
  int		j;
  int		k;
  t_tet		t;

  j = 0;
  t.x = tet.x;
  t.y = tet.y;
  t.t = malloc(sizeof(char *) * (my_strlen(tet.t[0]) + 1));
  while (j < my_strlen(tet.t[0]))
    {
      i = 0;
      k = tab_len(tet.t) - 1;
      t.t[j] = malloc(tab_len(tet.t) + 1);
      while (i < tab_len(tet.t))
	{
	  t.t[j][i] = tet.t[k][j];
	  k--;
	  i++;
	}
      t.t[j][i] = '\0';
      j++;
    }
  t.t[j] = NULL;
  if (is_ok(t, tab, tl) == 0 && can_move_r(t, tab, tc + 1) == 0)
    {
      free_tab(tet.t);
      tet.t = t.t;
    }
  else
    free_tab(t.t);
  return (tet);
}

WINDOW		*init(WINDOW *scr)
{
  score = 0;
  srand(time(NULL));
  scr = initscr();
  nodelay(scr, 1);
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, 1, 1);
  init_pair(2, 2, 2);
  init_pair(3, 3, 3);
  init_pair(4, 4, 4);
  init_pair(5, 5, 5);
  init_pair(6, 6, 6);
  init_pair(7, 1, 0);
  init_pair(8, 0, 1);
  init_pair(9, 1, 0);
  init_pair(10, 2, 0);
  init_pair(11, 3, 0);
  init_pair(12, 4, 0);
  init_pair(13, 5, 0);
  init_pair(14, 6, 0);
  return (scr);
}

int		game_over(char **t, t_tet tet, int len, WINDOW *scr)
{
  int		f;
  int		x;
  int		i;
  int		key;

  f = 0;
  x = 0;
  i = 1;
  if (is_ok(tet, t, 20) == 1)
    {
      while (42)
	{

	  clear();
	  attron(COLOR_PAIR(10));
	  mvprintw(2, (COLS / 2) - 26, " __ __ _____ _____    __    _____ _____ _____ _____ ");
	  mvprintw(3, (COLS / 2) - 26, "|  |  |     |  |  |  |  |  |     |     |   __|   __|");
	  mvprintw(4, (COLS / 2) - 26, "|_   _|  |  |  |  |  |  |__|  |  |  |  |__   |   __|");
	  mvprintw(5, (COLS / 2) - 26, "  |_| |_____|_____|  |_____|_____|_____|_____|_____|");
	  attroff(COLOR_PAIR(10));
	  mvprintw(9 + 3 * sin(f / 5), x, "   _______________    ");
	  mvprintw(10 + 3 * sin(f / 5), x, "  /               \\   ");
	  mvprintw(11 + 3 * sin(f / 5), x, " /                 \\  ");
	  mvprintw(12 + 3 * sin(f / 5), x, "/                   \\ ");
	  mvprintw(13 + 3 * sin(f / 5), x, "|   XXXX     XXXX   | ");
	  mvprintw(14 + 3 * sin(f / 5), x, "|   XXXX     XXXX   | ");
	  mvprintw(15 + 3 * sin(f / 5), x, "|   XXX       XXX   | ");
	  mvprintw(16 + 3 * sin(f / 5), x, "|         X         | ");
	  mvprintw(17 + 3 * sin(f / 5), x, "\\__      XXX     __/  ");
	  mvprintw(18 + 3 * sin(f / 5), x, "  |\\     XXX     /|   ");
	  mvprintw(19 + 3 * sin(f / 5), x, "  | |           | |   ");
	  mvprintw(20 + 3 * sin(f / 5), x, "  | I I I I I I I |   ");
	  mvprintw(21 + 3 * sin(f / 5), x, "  |  I I I I I I  |   ");
	  mvprintw(22 + 3 * sin(f / 5), x, "   \\_           _/    ");
	  mvprintw(23 + 3 * sin(f / 5), x, "    \\_         _/     ");
	  mvprintw(24 + 3 * sin(f / 5), x, "      \\_______/       ");
	  //nodelay(scr, 0);
	  mvprintw(28, (COLS / 2) - 5, "GAME OVER");
	  mvprintw(29, (COLS / 2) - 13, "APPUYER SUR Q POUR QUITTER");
	  refresh();
	  usleep(50000);
	  key = getch();
	  if (key == 'q')
	    {
	      endwin();
	      return (1);
	    }
	  f++;
	  x = x + i;
	  if (x == 0)
	    i = 1;
	  else if (x + 24 >= COLS)
	    i = -1;
	}
    }
  else
    return (0);
}

t_hs		*init_hs(t_hs *hs)
{
  hs = malloc(sizeof(t_hs) * 11);
}

void		tetrarena0(int f, int len)
{
  if ((f % 200) < 100) 
    {
      mvprintw(0 + len + 8 + 7, 56, "  O ");
      mvprintw(1 + len + 8 + 7, 56, "\\/V\\");
      mvprintw(2 + len + 8 + 7, 56, "  I/");
      mvprintw(3 + len + 8 + 7, 56, " / \\");
      mvprintw(4 + len + 8 + 7, 56, " | |");
      refresh();
    }
  else
    {
      mvprintw(0 + len + 8 + 7, 55, "  O ");
      mvprintw(1 + len + 8 + 7, 55, "\\/V\\");
      mvprintw(2 + len + 8 + 7, 55, "  I/");
      mvprintw(3 + len + 8 + 7, 55, " / \\");
      mvprintw(4 + len + 8 + 7, 55, " \\  \\");
      refresh();
    }
}

void		tetrarena1(int len)
{
  int		i;
  int		j;

  j = 0;
  while (j < 10 + 2)
    {
      i = 0;
      while (i < 60 + 2)
	{
	  if ((j == 0 && i == 0) || (j == 10 + 1 && i == 60 + 1))
	    mvprintw(j + len + 2 + 7, i, "/");
	  else if ((j == 10 + 1  && i == 0) || (j == 0 && i == 60 + 1))
	    mvprintw(j + len + 2 + 7, i, "\\");
	  else if (j == 0 || j == 10 + 1)
	    mvprintw(j + len + 2 + 7, i, "-");
	  else if (i == 0 || i == 60 + 1)
	    mvprintw(j + len + 2 + 7, i, "|");
	  i++;
	}
      j++;
    }
}

void		boss0(int len)
{
  mvprintw(len + 2 + 7, 5, "Chicken");
  mvprintw(len + 10 + 7, 1, "   o>");
  mvprintw(1 + len + 10 + 7, 1, ",(G) ");
  mvprintw(2 + len + 10 + 7, 1, " m   ");
}

void		boss1(int len)
{
  mvprintw(len + 2 + 7, 5, "Turkey");
  mvprintw(0 + len + 9 + 7, 1, "   ..");
  mvprintw(1 + len + 9 + 7, 1, "  _ °F");
  mvprintw(2 + len + 9 + 7, 1, ",( G)");
  mvprintw(3 + len + 9 + 7, 1, " m");

}

void		boss2(int len)
{
  mvprintw(len + 2 + 7, 5, "Crocodile");
  mvprintw(0 + len + 7 + 7, 1, "\"\"");
  mvprintw(1 + len + 7 + 7, 1, "| \"             mm");
  mvprintw(2 + len + 7 + 7, 1, "\\   \"\"\"\"\"\"\"\"\"\"\"  oo___");
  mvprintw(3 + len + 7 + 7, 1, " \\_            ______pp");
  mvprintw(4 + len + 7 + 7, 1, "   \\( )_____( )______/");
  mvprintw(5 + len + 7 + 7, 1, "     m \"     m \"");
}

void		boss3(int len)
{
  mvprintw(len + 2 + 7, 5, "Witcher");
  mvprintw(0 + len + 6 + 7, 1, " ---");
  mvprintw(1 + len + 6 + 7, 1, "|o o|");
  mvprintw(2 + len + 6 + 7, 1, " \\m/  \"+");
  mvprintw(3 + len + 6 + 7, 1, "  |  / \"");
  mvprintw(4 + len + 6 + 7, 1, " /|\\/");
  mvprintw(5 + len + 6 + 7, 1, "  |/");
  mvprintw(6 + len + 6 + 7, 1, " //\\");
}

void		boss4(int len)
{
  mvprintw(len + 2 + 7, 5, "Berserker");
  mvprintw(0 + len + 8 + 7, 1, "  O (-)");
  mvprintw(1 + len + 8 + 7, 1, "  M\\_|");
  mvprintw(2 + len + 8 + 7, 1, "  H  |");
  mvprintw(3 + len + 8 + 7, 1, " / \\");
  mvprintw(4 + len + 8 + 7, 1, "/  /");

}

void		boss5(int len)
{
  mvprintw(len + 2 + 7, 5, "Knigth");
  mvprintw(0 + len + 4 + 7, 1, "      _");
  mvprintw(1 + len + 4 + 7, 1, "     ||)");
  mvprintw(2 + len + 4 + 7, 1, "  ----|\\------>");
  mvprintw(3 + len + 4 + 7, 1, "      |      m___");
  mvprintw(4 + len + 4 + 7, 1, "  ----\\-----/ °__)");
  mvprintw(5 + len + 4 + 7, 1, " /     |      /");
  mvprintw(6 + len + 4 + 7, 1, "M(  )----(  )/");
  mvprintw(7 + len + 4 + 7, 1, "  ||||    ||||");
  mvprintw(8 + len + 4 + 7, 1, "  ||      ||");
}

void		boss6(int len)
{
  mvprintw(len + 2 + 7, 5, "Cyclope");
  mvprintw(0 + len + 3 + 7, 1, "           /\\");
  mvprintw(1 + len + 3 + 7, 1, "    (_)  </< \\>");
  mvprintw(2 + len + 3 + 7, 1, "    /o\\  <\\ >/>");
  mvprintw(3 + len + 3 + 7, 1, "  __\\-/_   ||");
  mvprintw(4 + len + 3 + 7, 1, " /  O-O \\_/|3");
  mvprintw(5 + len + 3 + 7, 1, "| /|:::|\\_/||");
  mvprintw(6 + len + 3 + 7, 1, "| ||~~~|   ()");
  mvprintw(7 + len + 3 + 7, 1, " mm|\\_/|");
  mvprintw(8 + len + 3 + 7, 1, "   || ||");
  mvprintw(9 + len + 3 + 7, 1, "  /_|/_|");
}

void		boss7(int len)
{
  mvprintw(len + 2 + 7, 5, "Golem");
  mvprintw(0 + len + 7 + 7, 1, "____");
  mvprintw(1 + len + 7 + 7, 1, " _ _|");
  mvprintw(2 + len + 7 + 7, 1, "  _ |");
  mvprintw(3 + len + 7 + 7, 1, "____|");
  mvprintw(4 + len + 7 + 7, 1, "   |--\\");
  mvprintw(5 + len + 7 + 7, 1, "       |");
}

void            boss8(int len)
{
  mvprintw(len + 2 + 7, 5, "The Mountain");
  mvprintw(0 + len + 3 + 7, 1, " ^^^^^     /\\");
  mvprintw(1 + len + 3 + 7, 1, " |  __\\    ||");
  mvprintw(2 + len + 3 + 7, 1, " | |__|    ||");
  mvprintw(3 + len + 3 + 7, 1, " __  |/    ||");
  mvprintw(4 + len + 3 + 7, 1, "/  \\   \\  =TT=");
  mvprintw(5 + len + 3 + 7, 1, "|()|  | \\__||");
  mvprintw(6 + len + 3 + 7, 1, "\\__/  |    ()");
  mvprintw(7 + len + 3 + 7, 1, "  || \\\\");
  mvprintw(8 + len + 3 + 7, 1, "  ||  ||");
  mvprintw(9 + len + 3 + 7, 1, "  |_\\ |_\\");
}

void            boss9(int len)
{
  mvprintw(len + 2 + 7, 5 + 7, "Nobody can beat the Dragon !");
  mvprintw(0 + len + 3 + 7, 1, "   ._\\\\\\_");
  mvprintw(1 + len + 3 + 7, 1, "  < \' \' \' \\");
  mvprintw(2 + len + 3 + 7, 1, " <\'_\\__  \'o");
  mvprintw(3 + len + 3 + 7, 1, "<\'/_(  \\_  \\");
  mvprintw(4 + len + 3 + 7, 1, "<_/\\_\\   \\__\"");
  mvprintw(5 + len + 3 + 7, 1, "\\_\\_\\_\\____");
  mvprintw(6 + len + 3 + 7, 1, " \\ \\_ .---.\\");
  mvprintw(7 + len + 3 + 7, 1, "  \\_\\_\\_\\  \"\"");
  mvprintw(8 + len + 3 + 7, 1, "  _)_)_)_\\");
  mvprintw(9 + len + 3 + 7, 1, " _//_/_/  )");

}

void		aff_boss(int len)
{
  void		(*t[10])(int);

  t[0] = &boss0;
  t[1] = &boss1;
  t[2] = &boss2;
  t[3] = &boss3;
  t[4] = &boss4;
  t[5] = &boss5;
  t[6] = &boss6;
  t[7] = &boss7;
  t[8] = &boss8;
  t[9] = &boss9;
  (*t[(int)lvl])(len);
}

void		anim_atk(char **t, int tl, int n, char **t2, int s, int c)
{
  int		i;
  int		j;
  int		k;
  int		d[10];

  d[0]= 48;
  d[1]= 47;
  d[2]= 30;
  d[3]= 45;
  d[4]= 46;
  d[5]= 35;
  d[6]= 40;
  d[7]= 45;
  d[8]= 40;
  d[9]= 40;

  if (n == 1)
    {
      i = 0;
      while (i < d[(int)lvl])
	{
	  clear();
	  aff(t);
	  tetrarena1(tl);
	  aff_boss(tl);
	  aff_gui(t2, s, c);
	  mvprintw(0 + tl + 8 + 7, 55 - i, "\\  O ");
	  mvprintw(1 + tl + 8 + 7, 55 - i, " \\/V\\");
	  mvprintw(2 + tl + 8 + 7, 55 - i, "   I/");
	  mvprintw(3 + tl + 8 + 7, 55 - i, "  / \\");
	  mvprintw(4 + tl + 8 + 7, 55 - i, "  \\  \\");
	  refresh();
	  usleep(50000);
	  i++;
	}
      clear();
      aff(t);
      aff_gui(t2, s, c);
      tetrarena1(tl);
      aff_boss(tl);
      aff_logo(6, tl);
      mvprintw(0 + tl + 8 + 7, 55 - i, "\\  O ");
      mvprintw(1 + tl + 8 + 7, 55 - i, " \\/V\\");
      mvprintw(2 + tl + 8 + 7, 55 - i, "   I/");
      mvprintw(3 + tl + 8 + 7, 55 - i, "  / \\");
      mvprintw(4 + tl + 8 + 7, 55 - i, "  \\  \\");
      refresh();
      usleep(50000 * 15);
      attron(COLOR_PAIR(7));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(7));
      refresh();
      usleep(50000);
      attron(COLOR_PAIR(8));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(8));
      refresh();
      usleep(50000);
      clear();
      aff(t);
      aff_gui(t2, s, c);
      tetrarena1(tl);
      aff_boss(tl);
      aff_logo(6, tl);
      mvprintw(0 + tl + 8 + 7, 54 - i, "   O ");
      mvprintw(1 + tl + 8 + 7, 54 - i, "__/V\\");
      mvprintw(2 + tl + 8 + 7, 54 - i, "   I/");
      mvprintw(3 + tl + 8 + 7, 54 - i, "  / \\");
      mvprintw(4 + tl + 8 + 7, 54 - i, "  \\  \\");
      refresh();
      usleep(50000 * 15);
      attron(COLOR_PAIR(7));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(7));
      refresh();
      usleep(50000);
      attron(COLOR_PAIR(8));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(8));
      refresh();
      usleep(50000);
      clear();
      aff(t);
      aff_gui(t2, s, c);
      tetrarena1(tl);
      aff_boss(tl);
      aff_logo(6, tl);
      mvprintw(0 + tl + 8 + 7, 54 - i, "  O ");
      mvprintw(1 + tl + 8 + 7, 54 - i, " /V\\");
      mvprintw(2 + tl + 8 + 7, 54 - i, "/ I/");
      mvprintw(3 + tl + 8 + 7, 54 - i, " / \\");
      mvprintw(4 + tl + 8 + 7, 54 - i, " \\  \\");
      refresh();
      usleep(50000 * 15);
      attron(COLOR_PAIR(7));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(7));
      refresh();
      usleep(50000);
      attron(COLOR_PAIR(8));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(8));
      refresh();
      usleep(50000);
    }
  else if (n == 2)
    {
      clear();
      aff(t);
      aff_gui(t2, s, c);
      tetrarena1(tl);
      aff_boss(tl);
      aff_logo(6, tl);
      mvprintw(tl + 7 + 7, 52, "  |");
      mvprintw(0 + tl + 8 + 7, 52, "--O-- O ");
      mvprintw(1 + tl + 8 + 7, 52, "  | \\/V\\");
      mvprintw(2 + tl + 8 + 7, 52, "      I/");
      mvprintw(3 + tl + 8 + 7, 52, "     / \\");
      mvprintw(4 + tl + 8 + 7, 52, "     | |");
      refresh();
      usleep(50000 * 15);
      i = 0;
      while (i < d[(int)lvl])
	{
	  clear();
	  aff(t);
	  aff_gui(t2, s, c);
	  tetrarena1(tl);
	  aff_boss(tl);
	  aff_logo(6, tl);
	  mvprintw(0 + tl + 8 + 7, 54, "   O ");
	  mvprintw(1 + tl + 8 + 7, 54, "__/V\\");
	  mvprintw(2 + tl + 8 + 7, 54, "   I/");
	  mvprintw(3 + tl + 8 + 7, 54, "  / \\");
	  mvprintw(4 + tl + 8 + 7, 54, "  \\  \\");
	  if (i % 2 == 0)
	    {
	      mvprintw(0 + tl + 8 + 7, 53 - i, "\\ /");
	      mvprintw(1 + tl + 8 + 7, 53 - i, " O");
	      mvprintw(2 + tl + 8 + 7, 53 - i, "/ \\");
	    }
	  else
	    {
	      mvprintw(0 + tl + 8 + 7, 52 - i, "  |");
	      mvprintw(1 + tl + 8 + 7, 52 - i, "--O--");
	      mvprintw(2 + tl + 8 + 7, 52 - i, "  |");
	    }
	  refresh();
	  usleep(50000 * 2);
	  i++;
	}
      attron(COLOR_PAIR(7));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(7));
      refresh();
      usleep(50000);
      attron(COLOR_PAIR(8));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(8));
      refresh();
      usleep(50000);
    }
  else if (n == 3)
    {
      clear();
      aff(t);
      aff_gui(t2, s, c);
      tetrarena1(tl);
      aff_boss(tl);
      aff_logo(6, tl);
      mvprintw(0 + tl + 8 + 7, 55, "  O ");
      mvprintw(1 + tl + 8 + 7, 55, "\\/V\\");
      mvprintw(2 + tl + 8 + 7, 55, "  I/");
      mvprintw(3 + tl + 8 + 7, 55, " / \\");
      mvprintw(4 + tl + 8 + 7, 55, " | |");
      attron(COLOR_PAIR(3));
      mvprintw(tl + 8 + 7, 55, "*");
      attroff(COLOR_PAIR(3));
      refresh();
      usleep(50000 * 15);
      i = 0;
      while (i < d[(int)lvl])
	{
	  clear();
	  aff(t);
	  aff_gui(t2, s, c);
	  tetrarena1(tl);
	  aff_boss(tl);
	  aff_logo(6, tl);
	  mvprintw(0 + tl + 8 + 7, 54, "   O ");
	  mvprintw(1 + tl + 8 + 7, 54, "__/V\\");
	  mvprintw(2 + tl + 8 + 7, 54, "   I/");
	  mvprintw(3 + tl + 8 + 7, 54, "  / \\");
	  mvprintw(4 + tl + 8 + 7, 54, "  \\  \\");
	  attron(COLOR_PAIR(1));
	  mvprintw(0 + tl + 8 + 7, 54 - i, "**");
	  mvprintw(1 + tl + 8 + 7, 53 - i, "*");
	  mvprintw(2 + tl + 8 + 7, 54 - i, "**");
	  attroff(COLOR_PAIR(1));
	  attron(COLOR_PAIR(3));
       	  mvprintw(1 + tl + 8 + 7, 54 - i, "**");
	  attroff(COLOR_PAIR(3));
	  refresh();
	  usleep(50000 * 2);
	  i++;
	}
      attron(COLOR_PAIR(7));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(7));
      refresh();
      usleep(50000);
      attron(COLOR_PAIR(8));
      mvprintw(tl + 7 + 7, 54 - i, "'");
      mvprintw(tl + 9 + 7, 54 - i, "'");
      mvprintw(tl + 11 + 7, 54 - i, "'");
      attroff(COLOR_PAIR(8));
      refresh();
      usleep(50000);
    }
  else if (n > 3)
    {
      clear();
      aff(t);
      aff_gui(t2, s, c);
      tetrarena1(tl);
      aff_boss(tl);
      aff_logo(6, tl);
      mvprintw(0 + tl + 8 + 7, 56, " O ");
      mvprintw(1 + tl + 8 + 7, 56, "/V|");
      mvprintw(2 + tl + 8 + 7, 56, " -");
      mvprintw(3 + tl + 8 + 7, 56, "/ \\");
      mvprintw(4 + tl + 8 + 7, 56, "| |");
      attron(COLOR_PAIR(6));
      mvprintw(tl + 10 + 7, 55, "*");
      attroff(COLOR_PAIR(6));
      refresh();
      usleep(50000 * 5);
      mvprintw(tl + 6 + 7, 40, "KA");
      refresh();
      usleep(50000 * 5);
      mvprintw(tl + 6 + 7, 42, "ME");
      refresh();
      usleep(50000 * 5);
      mvprintw(tl + 6 + 7, 44, "HA");
      refresh();
      usleep(50000 * 5);
      mvprintw(tl + 6 + 7, 46, "ME");
      refresh();
      usleep(50000 * 5);
      mvprintw(tl + 6 + 7, 48, "A");
      refresh();
      usleep(50000);
      mvprintw(tl + 6 + 7, 49, "A");
      refresh();
      usleep(50000);
      mvprintw(tl + 6 + 7, 50, "A");
      refresh();
      usleep(50000 * 2);
      mvprintw(tl + 6 + 7, 52, "!");
      refresh();
      mvprintw(tl + 6 + 7, 53, "!");
      refresh();
      usleep(50000);
      mvprintw(tl + 6 + 7, 54, "!");
      refresh();
      usleep(50000);
      i = 0;
      while (i < d[(int)lvl])
	{
	  attron(COLOR_PAIR(6));
	  mvprintw(2 + tl + 8 + 7, 54 - i, "**");
	  attroff(COLOR_PAIR(6));
	  /*attron(COLOR_PAIR(4));
	  mvprintw(1 + tl + 8, 55 - i, "*");
	  mvprintw(3 + tl + 8, 55 - i, "*");
	  attroff(COLOR_PAIR(4));*/
	  refresh();
	  usleep(50000);
	  i++;
	}
      k = 0;
      while (k < 10)
	{
	  attron(COLOR_PAIR(6));
	  j = 0;
	  while (j < LINES)
	    {
	      i = 0;
	      while (i < COLS)
		{
		  mvprintw(j, i, "*");
		  i++;
		}
	      j++;
	    }
	  attroff(COLOR_PAIR(6));
	  refresh();
	  usleep(100000);
	  clear();
	  aff(t);
	  aff_gui(t2, s, c);
	  tetrarena1(tl);
	  aff_boss(tl);
	  aff_logo(6, tl);
	  mvprintw(0 + tl + 8 + 7, 56, " O ");
	  mvprintw(1 + tl + 8 + 7, 56, "/V|");
	  mvprintw(2 + tl + 8 + 7, 56, " -");
	  mvprintw(3 + tl + 8 + 7, 56, "/ \\");
	  mvprintw(4 + tl + 8 + 7, 56, "| |");
	  refresh();
	  usleep(100000);
	  k++;
	}
    }
}

void		aff_logo(int f, int len)
{
  attron(COLOR_PAIR((f % (6 * 10)) / 10 + 9));
  mvprintw(0 + 1 + 1 * sin(f/5), ((len / 4) * 3) + 5 * cos(f/5) , " _____ _____ _____ _____ _____ _____ _____ _____ _____ ");
  mvprintw(1 + 1 + 1 * sin(f/5), ((len / 4) * 3) + 5 * cos(f/5) , "|_   _|   __|_   _| __  |  _  | __  |   __|   | |  _  |");
  mvprintw(2 + 1 + 1 * sin(f/5), ((len / 4) * 3) + 5 * cos(f/5) , "  | | |   __| | | |    -|     |    -|   __| | | |     |");
  mvprintw(3 + 1 + 1 * sin(f/5), ((len / 4) * 3) + 5 * cos(f/5) , "  |_| |_____| |_| |__|__|__|__|__|__|_____|_|___|__|__|");
  attroff(COLOR_PAIR((f % 6) + 9));
  refresh();
}

int		main(int ac, char **av, char **env)
{
  t_te		te;
  t_t		tab;
  int		key;
  int		s;
  int		r;
  int		f;
  char		**t;
  t_tet		tet;
  t_tet		tet_n;
  WINDOW	*scr;

  s = 0;
  if (ac == 2)
    lvl = my_getnbr(av[1]);
  else
    lvl = 0;
  read_tet(&te);
  tab = get_tab(te, tab);
  scr = init(scr);
  t = init_tab(20, 10);
  tet_n = init_tet(tab.tab_tet, tab.len);
  while (42)
    {
      f = 0;
      r = 0;
      tet = tet_n;
      tet_n = init_tet(tab.tab_tet, tab.len);
      if(game_over(t, tet, 20, scr) == 1)
	return (0);
      while (r == 0)
	{
	  clear();
	  aff_tet(tet);
	  aff(t);
	  aff_gui(tet_n.t, s, tet_n.col);
	  tetrarena0(f, 20);
	  tetrarena1(20);
	  aff_boss(20);
	  aff_logo(f, 20);
	  key = getch();
	  usleep (50000);
	  if (is_ok(tet, t, 20) == 1)
	    r = 1;
	  else if (key == KEY_DOWN && tet.y < 18)
	    tet.y++;
	  else if (key == KEY_UP)
	    tet = rotate(tet, t, 20, 10);
	  else if (key == KEY_RIGHT && can_move_r(tet, t, 10) == 0)
	    tet.x++;
	  else if (key == KEY_LEFT && can_move_l(tet, t) == 0)
	    tet.x--;
	  if (is_ok(tet, t, 20) == 0 && f % (11 - (int)lvl) == 0)
	    tet.y++;
	  if (f % 20 == 0)
	    s++;
	  f++;
	}
      t = past_tab(tet, t);
      free_tab(tet.t);
      t = check_line(t, 20, tet_n.t, s, tet_n.col);
      refresh();
    }
}
