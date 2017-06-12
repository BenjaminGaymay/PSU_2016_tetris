/*
** print_map.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Tue Feb 28 14:00:05 2017 enzo petitpierre
** Last update Sun Mar 19 15:06:58 2017 enzo petitpierre
*/

#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"
#include "chained_list.h"
#include "my.h"
#include "tetris.h"

static void	print_box(const t_tetris tetris)
{
  attron(COLOR_PAIR(11));
  mvprintw(LINES / 4 + 4, COLS / 6 + 2, " Score : %15d ", tetris.score);
  attron(COLOR_PAIR(12));
  mvprintw(LINES / 4 + 5, COLS / 6 + 2, " Level : %15d ", tetris.level);
  attron(COLOR_PAIR(7));
  mvprintw(LINES / 4 + 1, COLS / 6 + 1, "---------------------------");
  mvprintw(LINES / 4 + 2, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 3, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 4, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 5, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 6, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 7, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 8, COLS / 6 + 1, "|");
  mvprintw(LINES / 4 + 2, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 3, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 4, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 5, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 6, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 7, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 8, COLS / 6 + 27, "|");
  mvprintw(LINES / 4 + 9, COLS / 6 + 1, "---------------------------");
}

static void	print_high_score(const t_tetris tetris,
				 const int min, const int sec)
{
  attron(COLOR_PAIR(10));
  mvprintw(LINES / 4 + 7, COLS / 6 + 2, " High Score : %10d ", tetris.high);
  attron(COLOR_PAIR(9));
  move(LINES / 4 + 6, COLS / 6 + 2);
  printw(" Timer :           %02d:%02d ", min, sec);
  attron(COLOR_PAIR(8));
  mvprintw(LINES / 4 + 3, COLS / 6 + 2, " Line : %16d ", tetris.line);
}

static void	print_next_box(const t_tetris tetris, const int y)
{
  int		x;

  attron(COLOR_PAIR(7));
  x = -2;
  while (x != tetris.next->x + 2)
    {
      mvprintw((LINES / 2 - 2), (COLS * 0.7 + x), "-");
      mvprintw((LINES / 2 + y + 1), (COLS * 0.7 + x++), "-");
    }
  mvprintw((LINES / 2 - 1), (COLS * 0.7 - 2), "|");
  mvprintw((LINES / 2 - 1), (COLS * 0.7 + tetris.next->x + 1), "|");
  mvprintw((LINES / 2 + y), (COLS * 0.7 - 2), "|");
  mvprintw((LINES / 2 + y), (COLS * 0.7 + tetris.next->x + 1), "|");
  attron(COLOR_PAIR(8));
}

static void	print_next(const t_tetris tetris)
{
  int		y;
  int		x;

  y = 0;
  while (tetris.next->form[0][y] != NULL)
    {
      x = -1;
      attron(COLOR_PAIR(7));
      mvprintw((LINES / 2 + y), (COLS * 0.7 - 2), "|");
      attron(COLOR_PAIR(8));
      while (tetris.next->form[0][y][++x] != '\0')
	{
	  if (tetris.next->form[0][y][x] != ' ')
	    attron(COLOR_PAIR(tetris.next->color));
	  move((LINES / 2) + y, (COLS * 0.7) + x);
	  printw(&tetris.next->form[0][y][x]);
	  attron(COLOR_PAIR(8));
	}
      attron(COLOR_PAIR(7));
      mvprintw((LINES / 2 + y), (COLS * 0.7 + tetris.next->x + 1), "|");
      y++;
    }
  print_next_box(tetris, y);
}

void	print_my_map(const t_tetris tetris,
			     const int min, const int sec)
{
  int		x;
  int		y;

  print_box(tetris);
  print_high_score(tetris, min, sec);
  if (my_strcmp(tetris.option.w_next, "Yes") == 0)
    print_next(tetris);
  y = -1;
  while (tetris.debug_map[++y] != NULL)
    {
      x = -1;
      while (tetris.debug_map[y][++x] != '\0')
	{
	  move((LINES - tetris.rows) / 2 + y, (COLS - tetris.col) / 2 + x);
	  if (tetris.debug_map[y][x] >= 'a' && tetris.debug_map[y][x] <= 'z')
	    attron(COLOR_PAIR(tetris.debug_map[y][x] - 'a' + 1));
	  else if (tetris.debug_map[y][x] >= '1' && tetris.debug_map[y][x] <= '9')
	    attron(COLOR_PAIR(tetris.debug_map[y][x] - '0'));
	  else if (tetris.debug_map[y][x] == '+')
	    attron(COLOR_PAIR(7));
	  printw(" ");
	  attron(COLOR_PAIR(8));
	}
    }
}
