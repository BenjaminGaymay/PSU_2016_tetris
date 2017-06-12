/*
** my_str_isnum2.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/basics
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Mon Feb 27 13:22:34 2017 enzo petitpierre
** Last update Tue Mar  7 15:33:54 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my.h"
#include "tetris.h"

int	my_str_isnum2(char *str)
{
  int	i;
  int	f;

  i = 0;
  f = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	f++;
      i++;
    }
  return (f != 0 ? 0 : 1);
}
