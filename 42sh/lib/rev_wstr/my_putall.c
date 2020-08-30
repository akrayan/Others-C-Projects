#include <unistd.h>

void		my_putchar(char a)
{
  write(1, &a, 1);
}

void		my_putstr(char *str)
{
  int		i = 0;

  while (str[i])
    {
      write(1, &str[i], 1);
      ++i;
    }
}
