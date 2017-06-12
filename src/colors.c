/*
** colors.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Tue Feb 28 14:05:35 2017 enzo petitpierre
** Last update Sun Mar 19 15:05:57 2017 enzo petitpierre
*/

#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

void	my_init_color()
{
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(6, COLOR_CYAN, COLOR_CYAN);
  init_pair(7, COLOR_WHITE, COLOR_WHITE);
  init_pair(8, COLOR_WHITE, COLOR_BLACK);
  init_pair(9, COLOR_RED, COLOR_BLACK);
  init_pair(10, COLOR_GREEN, COLOR_BLACK);
  init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(12, COLOR_CYAN, COLOR_BLACK);
}

void	aff_term(const t_tetris tetris,
		 const int min, const int sec)
{
  clear();
  if (LINES < tetris.rows || COLS < tetris.col)
    {
      mvprintw(LINES / 2 - 1, (COLS - 8) / 2, "Increase");
      mvprintw(LINES / 2 + 1, (COLS - 8) / 2, "the term");
    }
  else
    print_my_map(tetris, min, sec);
  refresh();
}
