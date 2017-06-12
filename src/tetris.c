/*
** tetris.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Tue Feb 28 14:24:22 2017 enzo petitpierre
** Last update Tue Mar 14 10:01:10 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "tetris.h"
#include "use_array.h"

void	line_complete(t_tetris *tetris)
{
  int	x;
  int	y;
  int	let;

  y = tetris->rows;
  while (y > 0)
    {
      let = 0;
      x = tetris->col;
      while (x > 0)
	{
	  if (tetris->debug_map[y][x] >= 'a' && tetris->debug_map[y][x] <= 'z')
	    let++;
	  x--;
	}
      if (let == tetris->col)
	{
	  my_delete_line(tetris, y);
	  tetris->score += (10 * tetris->col);
	  if (tetris->score > tetris->high)
	    put_high(tetris);
	}
      y--;
    }
}

int	find_x_y(char **map, const int x_or_y)
{
  int	x;
  int	y;

  y = 0;
  while (map[++y] != NULL)
    {
      x = 0;
      while (map[y][++x] != '\0')
	{
	  if (map[y][x] >= '0' && map[y][x] <= '9')
	    return (x_or_y == 1 ? x : y);
	}
    }
  return (-1);
}

int	check_put_tetrimino(t_tetris *tetris)
{
  int	x;

  tetris->form = 0;
  x = (tetris->col + 1) / 2 - tetris->next->x / 2;
  if (put_tetrimino_in_map(tetris, tetris->next, 1, x) == FAILURE)
    return (FAILURE);
  tetris->next = rand_tetrimino(*tetris);
  return (SUCCESS);
}

int	check_fall_end(t_tetris *tetris)
{
  if (fall(*tetris) == 0)
    if (check_put_tetrimino(tetris) == FAILURE)
      return (FAILURE);
  return (SUCCESS);
}

void	fill_empty_map(char **map, const int rows, const int columns)
{
  int	y;
  int	x;

  y = 0;
  while (y < rows + 2)
    {
      x = 0;
      while (x < columns + 2)
	{
	  if (y == 0 || y == rows + 1)
	    map[y][x] = (x == 0 || x == columns + 1 ? '+' : '+');
	  else
	    map[y][x] = (x == 0 || x == columns + 1 ? '+' : ' ');
	  x++;
	}
      map[y][x] = '\0';
      y++;
    }
  map[y] = NULL;
}
