/*
** tetris2.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Fri Mar 10 14:53:20 2017 enzo petitpierre
** Last update Wed Mar 15 16:43:36 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "tetris.h"
#include "use_array.h"

static char	**malloc_my_map(int columns, const int rows)
{
  char		**map;
  int		i;

  if (!(map = malloc(sizeof(char *) * (rows + 3))))
    return (NULL);
  map[0] = NULL;
  i = 0;
  while (i < rows + 2)
    {
      if (!(map[i] = malloc(sizeof(char) * (columns + 3))))
	return (NULL);
      map[i][0] = '\0';
      i++;
    }
  map[i] = NULL;
  return (map);
}

static void	free_struct(t_tetriminos *tetriminos, t_tetris *tetris)
{
  t_tetriminos	*tmp;
  int	i;

  while (tetriminos != NULL)
    {
      i = 0;
      while (i < 4)
	free_array(tetriminos->form[i++]);
      tmp = tetriminos->next;
      free(tetriminos);
      tetriminos = tmp;
    }
  free_array(tetris->debug_map);
}

static void	set_tetris(t_tetris *tetris, t_koption *option,
			   t_tetriminos *tetriminos, char **debug_map)
{
  tetris->debug_map = debug_map;
  tetris->tetriminos = tetriminos;
  tetris->level = my_getnbr(option->level);
  tetris->score = 0;
  tetris->timer = 0;
  tetris->line = 0;
  tetris->option = *option;
}

int		launch_tetris(t_koption *option)
{
  t_tetriminos	*tetriminos;
  t_tetris	tetris;
  char		**debug_map;

  tetriminos = NULL;
  if (put_tetriminos_in_list(&tetriminos, option) == ERROR)
    return (ERROR);
  if (tetriminos == NULL)
    return (ERROR);
  tetris.rows = get_rows(option->map_size, ',');
  tetris.col = get_columns(option->map_size, ',');
  if ((debug_map = malloc_my_map(tetris.col, tetris.rows)) == NULL)
    return (ERROR);
  fill_empty_map(debug_map, tetris.rows, tetris.col);
  set_tetris (&tetris, option, tetriminos, debug_map);
  if (get_high(&tetris) == ERROR)
    return (ERROR);
  create_term(option, &tetris);
  free_struct(tetriminos, &tetris);
  return (SUCCESS);
}
