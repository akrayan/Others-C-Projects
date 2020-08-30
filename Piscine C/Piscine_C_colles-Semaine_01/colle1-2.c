/*
** colle1-2.c for colle1-2.c in /home/Rayan/Piscine_C_colles-Semaine_01
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Sat Oct  3 15:22:54 2015 AKKACHE Kaci
** Last update Sat Oct  3 17:47:26 2015 AKKACHE Kaci
*/
int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	cfal(int i, int j, int x, int y)
{
  if (i == 1)
    {
      my_putchar('/');
      while (j <= x - 2)
	{
	  my_putchar('*');
	  j = j + 1;
	}
      my_putchar('\\');
    }
  else if(i == y)
    {
      my_putchar('\\');
      while (j <= x - 2)
	{
	  my_putchar('*');
	  j = j + 1;
	}
      my_putchar('/');
    }
}

int	normal(int x, int y, int i, int j)
{
  while (i <= y)
    {
      if (i == 1 || i == y)
	{
	  cfal(i,j,x,y);
	}
      else
	{
	  while (j <= x)
	    {
	      if(j == 1 || j == x)
		{
		  my_putchar('*');
		}
	      else
		{
		  my_putchar(' ');
		}
	      j = j + 1;
	    }
	}
      my_putchar('\n');
      i = i + 1;
      j = 1;
    }
}

int	colle(int x, int y)
{
  int i;
  int j;  

  i = 1;
  j = 1;
  if (x == 1 || y == 1)
    {
      while(i <= y)
	{
	  while(j <= x)
	    {
              my_putchar('*');
	      j = j + 1;
	    }
	  my_putchar('\n');
	  j = 1;	  
	  i = i + 1;
	}
    }
  else
    {
      normal(x,y,i,j);
    }
}

int	main()
{
  colle(6,5);
  return (0);
}
