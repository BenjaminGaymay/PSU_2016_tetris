/*
** ncurse.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar  6 20:36:25 2017 Benjamin GAYMAY
** Last update Fri Mar 17 10:17:09 2017 Benjamin GAYMAY
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"
#include "my.h"

int	get_key(t_tetris *tetris)
{
  char	*s;

  s = my_read(0, 1, 0);
  if (s != NULL)
    {
      if ((my_strstr(s, tetris->option.keyleft) == 0))
	move_left(*tetris);
      else if ((my_strstr(s, tetris->option.keyright) == 0))
	move_right(*tetris);
      else if ((my_strstr(s, tetris->option.key_turn) == 0))
	turn(tetris);
      else if ((my_strstr(s, tetris->option.key_pause) == 0))
	{
	  my_read(1, 1, 0);
	  while ((my_strstr(s, tetris->option.key_pause)) != 0)
	    my_read(0, 1, 0);
	  my_read(1, 1, 0);
	}
      else if ((my_strstr(s, tetris->option.key_quit) == 0))
	return (FAILURE);
      else if ((my_strstr(s, tetris->option.key_drop) == 0))
	if (drop(tetris) == FAILURE)
	  return (FAILURE);
    }
  return (SUCCESS);
}

static clock_t		start_tetris_2(t_tetris *tetris, clock_t aff,
			       clock_t get_end, time_t start)
{
  time_t	end;
  int		min;
  int		sec;

  time(&end);
  min = (end - start) / 60;
  sec = (end - start) % 60;
  if (get_end - aff >= 15000)
    {
      aff = clock();
      aff_term(*tetris, min, sec);
    }
  return (aff);
}

static void	start_tetris(t_koption *option, t_tetris *tetris, int timer)
{
  time_t	get_start;
  clock_t	start;
  clock_t	aff;
  clock_t	end;

  time(&get_start);
  start = clock();
  aff = clock();
  option = option;
  while (1)
    {
      end = clock();
      if ((timer = 250000 - tetris->level * 30000) < 30000)
	timer = 30000;
      if (get_key(tetris) == FAILURE)
	return ;
      if (end - start >= timer)
	{
	  start = clock();
	  if (check_fall_end(tetris) == FAILURE)
	    return ;
	}
      line_complete(tetris);
      aff = start_tetris_2(tetris, aff, end, get_start);
    }
}

void		create_term(t_koption *option, t_tetris *tetris)
{
  t_tetriminos	*tmp;
  int		x;
  int		timer;

  initscr();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
  srand(time(NULL));
  start_color();
  my_init_color();
  tmp = rand_tetrimino(*tetris);
  x = (tetris->col + 1) / 2 - tmp->x / 2;
  tetris->form = 0;
  put_tetrimino_in_map(tetris, tmp, 1, x);
  tetris->next = rand_tetrimino(*tetris);
  timer = 0;
  start_tetris(option, tetris, timer);
  usleep(100000);
  aff_lose();
  usleep(300000);
  endwin();
}
