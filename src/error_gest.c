/*
** error_gest.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Wed Mar 15 10:26:04 2017 enzo petitpierre
** Last update Wed Mar 15 16:13:37 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

# define MINI(A, B) ((A) <= (B) ? (A) : (B))

char	**init_tab(t_koption *option)
{
  char	**seq;

  if ((seq = malloc(sizeof(char *) * 7)) == NULL)
    return (NULL);
  seq[0] = option->keyleft;
  seq[1] = option->keyright;
  seq[2] = option->key_pause;
  seq[3] = option->key_drop;
  seq[4] = option->key_quit;
  seq[5] = option->key_turn;
  seq[6] = NULL;
  return (seq);
}

int	check_sequences(t_koption *option)
{
  char	**seq;
  int	guest;
  int	min_len;
  int	current;

  current = 0;
  if ((seq = init_tab(option)) == NULL)
    return (FAILURE);
  while (seq[current + 1] != NULL)
    {
      guest = current + 1;
      while (seq[guest] != NULL)
	{
	  min_len = MINI(my_strlen(seq[current]), my_strlen(seq[guest]));
	  if ((my_strncmp(seq[current], seq[guest], min_len)) == 0)
	    return (FAILURE);
	  ++guest;
	}
      ++current;
    }
  free(seq);
  return (SUCCESS);
}
