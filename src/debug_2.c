/*
** debug_2.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Feb 24 14:10:28 2017 Benjamin GAYMAY
** Last update Fri Mar 17 09:48:28 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my_printf.h"
#include "use_array.h"
#include "tetris.h"
#include "my.h"

int		get_int(const char *s)
{
  static int	i = 0;
  static int	b = 0;
  int		nb;

  nb = 0;
  if (b != 0  && s[i - 1] == '\0')
    {
      i = 0;
      b = 0;
      return (-1);
    }
  while (s[i] >= '0' && s[i] <= '9')
    nb = nb * 10 + s[i++] - '0';
  i++;
  if (++b == 3)
    {
      i = 0;
      b = 0;
    }
  return (nb == 0 || i == 1 ? -1 : nb);
}

static int	check_first_line_2(char **tetrimino, const int b, const int fd)
{
  char		*s;
  int		i;

  i = 0;
  while ((s = get_next_line(fd)))
    {
      if (i < b)
	tetrimino[i++] = s;
      else
	{
	  free(s);
	  tetrimino[i] = NULL;
	  free_array(tetrimino);
	  return (FAILURE);
	}
    }
  tetrimino[i] = NULL;
  return (SUCCESS);
}

static int	star_len(char *s)
{
  int		i;
  int		f;

  i = 0;
  f = my_strlen(s) - 1;
  while (s[i] != '*' && s[i] != '\0')
    i++;
  while (s[f] != '*' && f >= 0)
    f--;
  return (f - i + 1);
}

int	check_len(char **tetrimino, const int a)
{
  int	i;
  int	len;
  int	save_len;

  i = 0;
  save_len = 0;
  while (tetrimino[i] != NULL)
    {
      len = star_len(tetrimino[i]);
      if (save_len < len)
	save_len = len;
      i++;
    }
  return (save_len == a ? SUCCESS : FAILURE);
}

int	check_first_line(char *s, const int fd, t_koption *debug)
{
  int	a;
  int	b;
  int	c;
  char	**tetrimino;

  a = get_int(s);
  b = get_int(s);
  c = get_int(s);
  free(s);
  if (a == -1 || b == -1 || c == -1)
    return (FAILURE);
  if ((tetrimino = malloc(sizeof(char *) * (b + 1))) == NULL)
    return (ERROR);
  tetrimino[0] = NULL;
  if (check_first_line_2(tetrimino, b, fd) == FAILURE)
    return (FAILURE);
  if (check_len(tetrimino, a) == FAILURE)
    return (FAILURE);
  if (a > get_rows(debug->map_size, ',')
      || b > get_columns(debug->map_size, ','))
    return (FAILURE);
  my_printf("Size %d*%d : Color %d :\n", a, b, c);
  my_showtab(tetrimino);
  free_array(tetrimino);
  return (SUCCESS);
}
