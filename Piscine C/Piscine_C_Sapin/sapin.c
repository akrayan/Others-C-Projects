/*
** sapin.c for sapin.c in /home/Rayan/Piscine_C_Sapin
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sun Oct  4 17:55:53 2015 AKKACHE Kaci
** Last update Sun Oct  4 23:28:00 2015 AKKACHE Kaci
*/
int	feuille2(int b, int taille, int p, int s, int nl, int l, int ns, int np)
{
  while (b <= taille)
    {
      p = p - 2;
      s = s + 1;
      if (b >= 4)
        {
          p = p - 2;
          s = s + 1;
        }
      while (nl <= l)
        {
          feuille(ns, s, np, p);
          my_putchar('\n');
          np = 1;
          p = p + 2;
          ns = 1;
          s = s - 1;
          nl = nl + 1;
        }
      l = l + 1;
      nl = 1;
      b = b + 1;
    } 
}

int	tronc(int nl, int s, int npm, int ns, int np, int taille)
{
  nl = 1;
  s = (npm / 2) - (taille / 2);
  ns = 1;
  np = 1;
  while (nl <= taille)
    {
      while (ns <= s)
        {
          my_putchar(' ');
          ns = ns + 1;
        }
      while (np <= taille)
        {
          my_putchar('|');
          np = np + 1;
        }
      nl = nl + 1;
      ns = 1;
      np = 1;
      my_putchar('\n');
    }
}

int feuille(int ns, int s, int np, int p)
{
  while (ns <= s)
    {
      my_putchar(' ');
      ns = ns + 1;
    }
  while (np <= p)
    {
      my_putchar('*');
      np = np + 1;
    }
}

int cpt(int npm, int taille, int nl, int l, int b)
{
  npm = 3;
  while (b <= taille)
    {
      npm = npm - 2;
      while (nl <= l)
        {
          npm = npm + 2;
          nl = nl + 1;
        }
      nl = 1;
      l = l + 1;
      b = b + 1;
    }
  return (npm);
}

void	sapin(int taille)
{
  int	b;
  int	nl;
  int	l;
  int	npm;
  int	p;
  int	np;
  int	s;
  int	ns;

  b = 1;
  nl = 1;
  l = 4;
  npm = cpt(npm, taille, nl, l, b); 
  nl = 0;
  np = 3;
  ns = 1;
  s = npm / 2;
  p = 1;
  feuille2(b, taille, p, s, nl, l, ns, np);
  tronc(nl, s, npm, ns, np, taille);
}
