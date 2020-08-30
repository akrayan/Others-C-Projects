/*
** my_aff_comb2.c for my_aff_comb2.sh in /home/Rayan/Piscine_C_J03
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Sep 30 16:13:25 2015 AKKACHE Kaci
** Last update Wed Sep 30 17:05:19 2015 AKKACHE Kaci
*/
int     my_putchar(char c)
{
  write(1, &c , 1);
}

int     my_nb(int a, int b, int c, int d)
{
  if( a + b > c + d )
    {
      my_putchar(d) ;   
      my_putchar(c) ;
      my_putchar(' ') ;
      my_putchar(b) ;
      my_putchar(a) ;
      if(!( d == 57 && c == 56 && b == 57 && a == 57 ))
	{
	  my_putchar(',') ;
	}
    }
  return a + 1;
}

int     my_aff_comb2()
{
  int nb1;
  int nb2;
  int nb3;
  int nb4;

  nb4 = 48 ;
    while ( nb4 < 58)
      { 
	nb3 = 48;
	while( nb3 < 58)
	  {
	    nb2 = 48;
	    while(nb2 < 58)
	      {
		nb1 = 49;
		while(nb1 < 58)
		  {
		    nb1 = my_nb(nb1, nb2, nb3, nb4) ;
		  }
		nb2 = nb2 + 1 ;
	      }
	    nb3 = nb3 + 1 ;
	  }
	nb4 = nb4 + 1 ;
      }
}

int     main()
{
  my_aff_comb2();
}
