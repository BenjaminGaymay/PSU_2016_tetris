/*
** option.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar 13 15:48:44 2017 Benjamin GAYMAY
** Last update Tue Mar 14 15:56:33 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <term.h>
#include "my.h"
#include "option.h"

int	init_option(t_koption *options, char **envp)
{
  int	err;
  int	i;

  i = -1;
  while (envp[++i] != NULL && my_strncmp("TERM=", envp[i], 5) != 0);
  options->term = &envp[i][5];
  if (setupterm(&envp[i][5], 1, &err) == -1)
    return (84);
  options->key_quit = "Q\0";
  options->key_pause = " \0";
  options->map_size = "20,10\0";
  options->w_next = "Yes\0";
  options->debug = "false\0";
  options->help = "false\0";
  options->level = "1\0";
  if ((options->keyleft = tigetstr("kcub1")) == NULL ||
      (options->keyright = tigetstr("kcuf1")) == NULL ||
      (options->key_turn = tigetstr("kcuu1")) == NULL ||
      (options->key_drop = tigetstr("kcud1")) == NULL)
    return (84);
  return (0);
}
