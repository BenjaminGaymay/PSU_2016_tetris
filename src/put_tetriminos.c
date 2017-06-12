/*
** put_tetriminos.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar  6 20:57:27 2017 Benjamin GAYMAY
** Last update Mon Mar 13 13:24:23 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "tetris.h"
#include "chained_list.h"

t_tetriminos	*rand_tetrimino(const t_tetris tetris)
{
  t_tetriminos	*tmp;
  int		i_max;
  int		i;

  i_max = rand() %my_len_list(tetris.tetriminos);
  i = -1;
  tmp = tetris.tetriminos;
  while (++i < i_max)
    tmp = tmp->next;
  return (tmp);
}

int	can_put_tetrimino_in_map(t_tetris *tet, t_tetriminos *tmp,
				 int y, const int x)
{
  int	x1;
  int	x2;
  int	y2;

  y2 = -1;
  while (tmp->form[tet->form][++y2] != NULL)
    {
      x1 = x;
      x2 = -1;
      while (tmp->form[tet->form][y2][++x2] != '\0')
	{
	  if (tet->debug_map[y][x1++] != ' ')
	    return (FAILURE);
	}
      y++;
    }
  return (SUCCESS);
}

int	put_tetrimino_in_map(t_tetris *tetris,
			     t_tetriminos *tmp, int y, const int x)
{
  int	x1;
  int	x2;
  int	y2;

  y2 = -1;
  if (can_put_tetrimino_in_map(tetris, tmp, y, x) == FAILURE)
    return (FAILURE);
  while (tmp->form[tetris->form][++y2] != NULL)
    {
      x1 = x;
      x2 = -1;
      while (tmp->form[tetris->form][y2][++x2] != '\0')
	{
	  if (tmp->form[tetris->form][y2][x2] == ' ')
	    tetris->debug_map[y][x1++] = ' ';
	  else
	    tetris->debug_map[y][x1++] = tmp->color + '0';
	}
      y++;
    }
  tetris->actual = tmp->id;
  return (SUCCESS);
}
