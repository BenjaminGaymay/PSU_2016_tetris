/*
** delete.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar  6 20:46:09 2017 Benjamin GAYMAY
** Last update Tue Mar 14 10:00:51 2017 Benjamin GAYMAY
*/

#include "tetris.h"

void		my_delete_line(t_tetris *tetris, int y)
{
  static int	i = 0;
  int		x;

  while (y > 1)
    {
      x = 0;
      while (++x <= tetris->col)
	if (tetris->debug_map[y][x] >= 'a' && tetris->debug_map[y][x] <= 'z')
	  tetris->debug_map[y][x] = tetris->debug_map[y - 1][x];
      y--;
    }
  tetris->line += 1;
  if (++i == 10)
    {
      tetris->level += 1;
      i = 0;
    }
}

void	delete_tetrimino(t_tetris *tetris, int *save_x, int *save_y)
{
  int	x;
  int	y;

  y = 0;
  while (++y <= tetris->rows + 1)
    {
      x = 0;
      while (++x <= tetris->col + 1)
	{
	  if (tetris->debug_map[y][x] >= '0' && tetris->debug_map[y][x] <= '9')
	    {
	      if (*save_y == 0)
		{
		  *save_y = y;
		  *save_x = x;
		}
	      if (*save_x > x)
		*save_x = x;
	      tetris->debug_map[y][x] = ' ';
	    }
	}
    }
}
