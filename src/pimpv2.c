/*
** pimpv2.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
** 
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
** 
** Started on  Fri Mar 17 13:11:32 2017 enzo petitpierre
** Last update Fri Mar 17 15:26:49 2017 enzo petitpierre
*/

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	lose_one()
{
  int	x;
  int	y;

  y = 0;
  while (y != LINES)
    {
      x = 0;
      while (x != COLS)
	{
	  attron(COLOR_PAIR(my_rand(1, 7)));
	  mvprintw(y, x, "#");
	  usleep((LINES + COLS) / 2);
	  refresh();
	  x++;
	}
      y++;
    }
  return (SUCCESS);
}

void	print_diag(int x, int y)
{
  while (x != 0)
    {
      attron(COLOR_PAIR(my_rand(1, 7)));
      mvprintw(y++, x--, "#");
      refresh();
      usleep(10);
    }
}

int	my_rand(int min, int max)
{
  return (rand() % max + min);
}

void		snake()
{
  static int	x = 0;
  static int	y = 0;
  int		i;

  i = 0;
  while (i != 6)
    {
      attron(COLOR_PAIR(i + 1));
      if (x + 1 == COLS && y + 1 != LINES)
	mvprintw(y++, x, "#");
      else if (x == 0 && y != 0)
	mvprintw(y--, x, "#");
      else if (y + 1 == LINES)
	mvprintw(y, x--, "#");
      else
	mvprintw(y, x++, "#");
      i++;
    }
}
