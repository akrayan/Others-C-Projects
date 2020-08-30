/*
** my_aff_comb.c for my_aff_comb in /home/Rayan/Piscine_C_J03
** 
** Made by AKKACHE Kaci
** Login   <Rayan@epitech.net>
** 
** Started on  Wed Sep 30 15:59:19 2015 AKKACHE Kaci
** Last update Wed Sep 30 16:05:05 2015 AKKACHE Kaci
*/
int     my_nb(int a, int b, int c)
{
  if( c < b && b < a )
    {
      my_putchar(c) ;
      my_putchar(b) ;
      my_putchar(a) ;
      if(!( c == 55 && b == 56 && a == 57 ))
        {
          my_putchar(',') ;
          my_putchar(' ') ;
        }
    }
}

int     my_aff_comb()
{
  int nb1;
  int nb2;
  int nb3;
  
  nb3 = 48;
  while( nb3 < 58)
    {
      nb2 = 49;
      while(nb2 < 58)
	{
	  nb1 = 50;
	  while(nb1 < 58)
	    {
	      my_nb(nb1, nb2, nb3) ;
	      nb1 = nb1 + 1 ;
	    }
	  nb2 = nb2 + 1 ;
	}
      nb3 = nb3 + 1 ;
    }
}
