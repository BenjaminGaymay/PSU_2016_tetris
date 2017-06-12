/*
** my_str_isnum.c for my_str_isnum in /home/benjamin.g/delivery/CPool_Day06
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Oct 10 21:45:18 2016 Benjamin GAYMAY
** Last update Tue Mar  7 15:35:12 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my.h"
#include "tetris.h"

int	my_str_isnum(char *str)
{
  int	i;
  int	f;
  int	star;

  i = 0;
  f = 0;
  star = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ',')
	star++;
      else if ((str[i] < '0') || (str[i] > '9'))
	f++;
      i++;
    }
  return (star == 1 && f == 1 ? 0 : 1);
}
