/*
** debug.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Feb 21 10:53:23 2017 Benjamin GAYMAY
** Last update Sun Mar 19 14:56:51 2017 enzo petitpierre
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

static void	free_bad_tetriminos(char *s, const int fd, t_koption *debug)
{
  if (check_first_line(s, fd, debug) == FAILURE)
    {
      my_printf("Error\n");
      while ((s = get_next_line(fd)))
	free(s);
    }
}

static char	*remove_end(char *s)
{
  int		i;

  i = my_strlen(s);
  while (--i != 0 && s[i] != '.')
    s[i] = '\0';
  s[i] = '\0';
  return (s);
}

int	aff_tetriminos(char **t, t_koption *debug)
{
  int		i;
  int		fd;
  char		*s;
  char		*name;

  i = 0;
  while (t[i] != NULL)
    {
      fd = open(name = my_malloc_strcat("./tetriminos/\0", t[i]), O_RDONLY);
      my_printf("Tetriminos : Name %s : ", remove_end(t[i]));
      if (fd == -1)
	return (ERROR);
      free(name);
      if ((s = get_next_line(fd)))
	free_bad_tetriminos(s, fd, debug);
      else
	my_printf("Error\n");
      close(fd);
      i++;
    }
  return (SUCCESS);
}

void	ascii_order(char **t)
{
  int		i;
  int		f;
  char		*tmp;

  i = 0;
  f = 0;
  while (t[f] != NULL)
    f++;
  while (f != 0)
    {
      i = 0;
      while (t[i + 1] != NULL)
	{
	  if (my_strcmp(t[i], t[i + 1]) > 0)
	    {
	      tmp = t[i];
	      t[i] = t[i + 1];
	      t[i + 1] = tmp;
	    }
	  i++;
	}
      f--;
    }
}

int	get_tetriminos_name(DIR *repository, char **tetriminos_name)
{
  struct dirent	*d_file;
  int		i;

  i = 0;
  while ((d_file = readdir(repository)) != NULL)
    {
      if (my_end_strcmp(d_file->d_name, ".tetrimino") == 0 &&
	  d_file->d_type == DT_REG)
	{
	  tetriminos_name[i] = d_file->d_name;
	  i++;
	}
    }
  tetriminos_name[i] = NULL;
  if (tetriminos_name[0] == NULL)
    return (ERROR);
  return (SUCCESS);
}
