/*
** pimp.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sat Mar 11 18:17:08 2017 Benjamin GAYMAY
** Last update Fri Mar 17 15:26:51 2017 enzo petitpierre
*/

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	lose_two()
{
  int	x;
  int	y;

  x = 0;
  while (x != COLS)
    {
      y = 0;
      while (y != LINES)
	{
	  attron(COLOR_PAIR(my_rand(1, 7)));
	  mvprintw(y, x, "#");
	  mvprintw(y, (COLS - x ) % 2 == 0 ? COLS - x - 1 : COLS - x, "#");
	  usleep((LINES + COLS) / 2);
	  refresh();
	  y++;
	}
      x += 2 ;
    }
  return (SUCCESS);
}

int	my_random()
{
  int	x;
  int	y;
  int	i;

  i = 0;
  while (++i != 35000)
    {
      x = my_rand(0, COLS);
      y = my_rand(0, LINES);
      attron(COLOR_PAIR(my_rand(1, 7)));
      mvprintw(y, x, "#");
      refresh();
      usleep(10);
    }
  return (SUCCESS);
}

int	diag()
{
  int	save_y;
  int	save_x;

  save_y = 0;
  save_x = 1;
  while (save_y != LINES)
    {
      save_x--;
      while (save_x != COLS)
	{
	  print_diag(save_x, save_y);
	  save_x++;
	}
      save_y++;
    }
  return (SUCCESS);
}

int	(*ptr_lose[5])() =
{
  lose_one,
  lose_two,
  my_random,
  diag
};

void	aff_lose()
{
  ptr_lose[my_rand(0, 4)]();
}
