/*
** flag.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 20 14:43:09 2017 Benjamin GAYMAY
** Last update Sat Mar 18 14:21:58 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"

int		let_l(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0)
    {
      option->level = "\0";
      return (FAILURE);
    }
  if (my_str_isnum2(s) == 0)
    return (FAILURE);
  option->level = s;
  return (SUCCESS);
}

int		let_kp(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->key_pause = "\0";
      return (FAILURE);
    }
  else
    option->key_pause = s;
  return (SUCCESS);
}

int		let_m(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->map_size = "\0";
      return (FAILURE);
    }
  option->map_size = s;
  if (my_str_isnum(s) == 0)
    return (FAILURE);
  else
    if (get_rows(s, ',') == 0 || get_columns(s, ',') == 0)
      return (FAILURE);
  return (SUCCESS);
}

int	let_w(char *s, t_koption *option)
{
  s = s;
  option->w_next = "No\0";
  return (SUCCESS);
}

int	let_d(char *s, t_koption *option)
{
  s = s;
  option->debug = "true\0";
  return (SUCCESS);
}
