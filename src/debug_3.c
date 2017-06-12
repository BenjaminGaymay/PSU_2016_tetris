/*
** debug_3.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
** 
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
** 
** Started on  Sun Mar 19 14:50:01 2017 enzo petitpierre
** Last update Sun Mar 19 14:51:53 2017 enzo petitpierre
*/

#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include "get_next_line.h"
#include "my_printf.h"
#include "tetris.h"
#include "my.h"

int	debug_tetriminos(t_koption *debug)
{
  DIR		*repository;
  char		**tetriminos_name;
  int		i;

  if ((i = count_tetriminos()) == 0)
    return (ERROR);
  if (!(tetriminos_name = malloc(sizeof(char *) * (i + 1))))
    return (ERROR);
  tetriminos_name[0] = NULL;
  my_printf("Tetriminos : %d\n", i);
  if ((repository = opendir("./tetriminos")) == NULL)
    return (ERROR);
  if (get_tetriminos_name(repository, tetriminos_name) == ERROR)
    return (ERROR);
  ascii_order(tetriminos_name);
  if (aff_tetriminos(tetriminos_name, debug) == ERROR)
    return (ERROR);
  closedir(repository);
  return (SUCCESS);
}

int		press_any_key()
{
  struct termios	old_t;
  struct termios	new_t;
  char			c;

  if (ioctl(1, TCGETS, &old_t) == -1)
    return (ERROR);
  new_t = old_t;
  new_t.c_lflag &= ~ECHO;
  new_t.c_lflag &= ~ICANON;
  if ((ioctl(1, TCSETS, &new_t) == -1)
      || (read(1, &c, 1) == - 1)
      || (ioctl(1, TCSETS, &old_t) == -1))
    return (ERROR);
  return (SUCCESS);
}

int	show_debug_struct(t_koption *debug)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : %S\n", debug->keyleft);
  my_printf("Key Right : %S\n", debug->keyright);
  my_printf("Key Turn : %S\n", debug->key_turn);
  my_printf("Key Drop : %S\n", debug->key_drop);
  my_printf("Key Quit : %S\n", debug->key_quit);
  my_printf("Key Pause : %S\n", debug->key_pause);
  my_printf("Next : %s\n", debug->w_next);
  my_printf("Level : %s\n", debug->level);
  my_printf("Size : %d", get_rows(debug->map_size, ','));
  my_printf("*%d\n", get_columns(debug->map_size, ','));
  if (debug_tetriminos(debug) == ERROR)
    return (ERROR);
  my_printf("Press any key to start Tetris");
  if ((press_any_key()) == ERROR)
    return (ERROR);
  my_putchar('\n');
  return (SUCCESS);
}
