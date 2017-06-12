/*
** my_showtab.c for my_showtab in /home/benjamin.g/save/Create/library
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 17 20:56:55 2017 Benjamin GAYMAY
** Last update Sun Feb 26 16:43:03 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"

void	my_showtab(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      my_putstr(array[i++]);
      my_putchar('\n');
    }
}
