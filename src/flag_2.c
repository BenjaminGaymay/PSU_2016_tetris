/*
** flag_2.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Feb 24 14:22:05 2017 Benjamin GAYMAY
** Last update Sat Mar 18 14:25:32 2017 Benjamin GAYMAY
*/

#include "tetris.h"

int		let_kl(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->keyleft = "\0";
      return (FAILURE);
    }
  else
    option->keyleft = s;
  return (SUCCESS);
}

int		let_kr(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->keyright = "\0";
      return (FAILURE);
    }
  else
    option->keyright = s;
  return (SUCCESS);
}

int		let_kt(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->key_turn = "\0";
      return (FAILURE);
    }
  else
    option->key_turn = s;
  return (SUCCESS);
}

int		let_kd(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->key_drop = "\0";
      return (FAILURE);
    }
  else
    option->key_drop = s;
  return (SUCCESS);
}

int		let_kq(char *s, t_koption *option)
{
  static int	i;

  if (i != 0)
    return (FAILURE);
  ++i;
  if (s == 0 || s[0] == '\0')
    {
      option->key_quit = "\0";
      return (FAILURE);
    }
  else
    option->key_quit = s;
  return (SUCCESS);
}
