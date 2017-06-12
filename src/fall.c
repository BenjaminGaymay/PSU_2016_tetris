/*
** fall.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar  6 21:47:39 2017 Benjamin GAYMAY
** Last update Tue Mar 14 16:15:25 2017 Benjamin GAYMAY
*/

#include "tetris.h"

int	nb_to_let(t_tetris tetris)
{
  int	x;
  int	y;

  y = 1;
  while (y <= tetris.rows)
    {
      x = 1;
      while (x <= tetris.col)
	{
	  if (tetris.debug_map[y][x] >= '0' && tetris.debug_map[y][x] <= '9')
	    tetris.debug_map[y][x] = tetris.debug_map[y][x] + '0';
	  x++;
	}
      y++;
    }
  return (0);
}

int	can_i_fall(t_tetris tetris)
{
  int	x;
  int	y;

  y = tetris.rows;
  while (y > 0)
    {
      x = 1;
      while (x <= tetris.col)
	{
	  if (tetris.debug_map[y][x] >= '0' && tetris.debug_map[y][x] <= '9')
	    if (tetris.debug_map[y + 1][x] != ' ' &&
		(tetris.debug_map[y + 1][x] < '0' ||
		 tetris.debug_map[y + 1][x] > '9'))
	      return (0);
	  x++;
	}
      y--;
    }
  return (1);
}

int	fall(t_tetris tetris)
{
  int	x;
  int	y;

  y = tetris.rows;
  if (can_i_fall(tetris) == 0)
    return (nb_to_let(tetris));
  while (y > 0)
    {
      x = 1;
      while (x <= tetris.col)
	{
	  if (tetris.debug_map[y][x] >= '0' && tetris.debug_map[y][x] <= '9')
	    {
	      tetris.debug_map[y + 1][x] = tetris.debug_map[y][x];
	      tetris.debug_map[y][x] = ' ';
	    }
	  x++;
	}
      y--;
    }
  return (1);
}

int	drop(t_tetris *tetris)
{
  my_read(1, 1, 0);
  while (fall(*tetris) != 0);
  tetris->form = 0;
  return (check_put_tetrimino(tetris));
}
