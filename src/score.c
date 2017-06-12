/*
** score.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar  7 11:19:05 2017 Benjamin GAYMAY
** Last update Mon Mar 13 12:40:08 2017 Benjamin GAYMAY
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "tetris.h"
#include "get_next_line.h"

static char	*int_to_str(int nb)
{
  char		*s;
  int		i;
  int		tmp;

  tmp = nb;
  i = 1;
  while ((tmp /= 10) > 0)
    ++i;
  if ((s = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  s[i] = '\0';
  while (i--)
    {
      s[i] = nb % 10 + '0';
      nb /= 10;
    }
  return (s);
}

void	put_high(t_tetris *tetris)
{
  int	fd;
  char	*s;

  tetris->high = tetris->score;
  if ((fd = open("./.highscore\0", O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
    return ;
  s = int_to_str(tetris->high);
  write(fd, s, my_strlen(s));
  free(s);
  close(fd);
}

int	get_high(t_tetris *tetris)
{
  int	fd;
  char	*s;

  if ((fd = open("./.highscore\0", O_RDONLY)) == -1)
    tetris->high = 0;
  else
    {
      s = get_next_line(fd);
      tetris->high = (s != NULL ? my_getnbr(s) : 0);
      close(fd);
    }
  return (SUCCESS);
}
