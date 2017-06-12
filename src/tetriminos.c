/*
** tetriminos.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sun Feb 26 15:53:32 2017 Benjamin GAYMAY
** Last update Sun Mar 19 14:36:52 2017 enzo petitpierre
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "get_next_line.h"
#include "chained_list.h"
#include "tetris.h"
#include "my.h"

static int	get_x_y(char **form1, const char x_or_y)
{
  int		x;
  int		y;
  int		max_x;

  y = 0;
  max_x = 0;
  while (form1[y] != NULL)
    {
      x = 0;
      while (form1[y][x] != '\0')
	x++;
      if (x > max_x)
	max_x = x;
      y++;
    }
  return (x_or_y == 'x' ? max_x : y);
}

static void	replace_in_form(char **form1, char **form2,
				const int x, int nb_line)
{
  int		x2;
  int		y1;

  x2 = 0;
  y1 = nb_line - 1;
  while (y1 >= 0)
    {
      form2[x][x2] = (form1[y1][x] == '\0' ? ' ' : form1[y1][x]);
      y1--;
      x2++;
    }
  form2[x][x2] = '\0';
}

char	**get_next_form(char **form1)
{
  char	**form2;
  int	nb_line;
  int	x;
  int	x_max;

  x_max = get_x_y(form1, 'x');
  nb_line = get_x_y(form1, 'y');
  if ((form2 = malloc(sizeof(char *) * (x_max + 1))) == NULL)
    return (NULL);
  x = 0;
  while (x < x_max)
    {
      if ((form2[x] = malloc(sizeof(char) * (nb_line + 1))) == NULL)
	return (NULL);
      replace_in_form(form1, form2, x, nb_line);
      x++;
    }
  form2[x] = NULL;
  my_r_space(form2);
  return (form2);
}

void	my_r_space(char **tetrimino)
{
  int	y;
  int	x;

  y = 0;
  while (tetrimino[y] != NULL)
    {
      x = my_strlen(tetrimino[y]) - 1;
      while (x >= 0 && tetrimino[y][x] == ' ')
	tetrimino[y][x--] = '\0';
      y++;
    }
}

char	**get_my_tetrimino(int fd, t_piece *piece_info,
				   t_koption *option)
{
  char		**tetrimino;
  char		*s;
  int		i;

  if (!(s = get_next_line(fd)))
    return (NULL);
  piece_info->x = get_int(s);
  piece_info->y = get_int(s);
  piece_info->color = get_int(s);
  if (piece_info->x == -1 || piece_info->y == -1 || piece_info->color == -1)
    return (NULL);
  if (piece_info->x > get_rows(option->map_size, ',') ||
      piece_info->y > get_columns(option->map_size, ','))
    return (NULL);
  if ((tetrimino = malloc(sizeof(char *) * (piece_info->y + 1))) == NULL)
    return (NULL);
  tetrimino[0] = NULL;
  i = 0;
  while ((i < piece_info->y) && ((s = get_next_line(fd)) != NULL))
    tetrimino[i++] = s;
  tetrimino[i] = NULL;
  my_r_space(tetrimino);
  return (tetrimino);
}
