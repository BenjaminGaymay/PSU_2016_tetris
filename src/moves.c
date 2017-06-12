/*
** moves.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar  6 20:41:09 2017 Benjamin GAYMAY
** Last update Tue Mar 14 16:13:56 2017 Benjamin GAYMAY
*/

#include "tetris.h"

static int	can_i_move_left(const t_tetris tetris)
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
	    if (tetris.debug_map[y][x - 1] != ' ' &&
		!(tetris.debug_map[y][x - 1] >= '0' &&
		  tetris.debug_map[y][x - 1] <= '9'))
	      return (0);
	  x++;
	}
      y--;
    }
  return (1);
}

void	move_left(t_tetris tetris)
{
  int	x;
  int	y;

  my_read(1, 1, 0);
  y = tetris.rows;
  if (can_i_move_left(tetris) == 0)
    return ;
  while (y > 0)
    {
      x = 1;
      while (x <= tetris.col)
	{
	  if (x > 1 &&
	      (tetris.debug_map[y][x] >= '0' && tetris.debug_map[y][x] <= '9'))
	    {
	      tetris.debug_map[y][x - 1] = tetris.debug_map[y][x];
	      tetris.debug_map[y][x] = ' ';
	    }
	  x++;
	}
      y--;
    }
}

static int	can_i_move_right(const t_tetris tetris)
{
  int	x;
  int	y;

  y = tetris.rows;
  while (y > 0)
    {
      x = tetris.col;
      while (x > 0)
	{
	  if (tetris.debug_map[y][x] >= '0' && tetris.debug_map[y][x] <= '9')
	    if (tetris.debug_map[y][x + 1] != ' ' &&
		!(tetris.debug_map[y][x + 1] >= '0' &&
		  tetris.debug_map[y][x + 1] <= '9'))
	      return (0);
	  x--;
	}
      y--;
    }
  return (1);
}

void	move_right(t_tetris tetris)
{
  int	x;
  int	y;

  my_read(1, 1, 0);
  y = tetris.rows;
  if (can_i_move_right(tetris) == 0)
    return ;
  while (y > 0)
    {
      x = tetris.col;
      while (x > 0)
	{
	  if (tetris.debug_map[y][x] >= '0' && tetris.debug_map[y][x] <= '9')
	    {
	      tetris.debug_map[y][x + 1] = tetris.debug_map[y][x];
	      tetris.debug_map[y][x] = ' ';
	    }
	  x--;
	}
      y--;
    }
}

void		turn(t_tetris *tetris)
{
  t_tetriminos	*tmp;
  int		save_form;
  int		save_x;
  int		save_y;

  my_read(1, 1, 0);
  save_x = 0;
  save_y = 0;
  save_form = tetris->form;
  delete_tetrimino(tetris, &save_x, &save_y);
  tmp = tetris->tetriminos;
  while (tetris->actual != tmp->id)
    tmp = tmp->next;
  tetris->form = (tetris->form + 1 == 4 ? 0 : tetris->form + 1);
  if (can_put_tetrimino_in_map(tetris, tmp, save_y, save_x) == FAILURE)
    tetris->form = save_form;
  put_tetrimino_in_map(tetris, tmp, save_y, save_x);
}
