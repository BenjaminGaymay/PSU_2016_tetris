/*
** tetriminos_2.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
** 
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
** 
** Started on  Sun Mar 19 14:30:49 2017 enzo petitpierre
** Last update Sun Mar 19 14:31:24 2017 enzo petitpierre
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "get_next_line.h"
#include "chained_list.h"
#include "tetris.h"
#include "my.h"

int	get_fd(char *name)
{
  int		fd;
  char		*s;

  s = my_malloc_strcat("./tetriminos/\0", name);
  fd = open(s, O_RDONLY);
  free(s);
  return (fd);
}

void	free_gnl(int fd)
{
  char	*s;

  while ((s = get_next_line(fd)))
    free(s);
  close(fd);
}

int		put_tetriminos_in_list(t_tetriminos **tet, t_koption *option)
{
  DIR		*repository;
  struct dirent	*d_file;
  t_piece	piece_info;
  char		**tetrimino;
  int		fd;

  tetrimino = NULL;
  if ((repository = opendir("./tetriminos")) == NULL)
    return (ERROR);
  while ((d_file = readdir(repository)) != NULL)
    {
      if (my_end_strcmp(d_file->d_name, ".tetrimino") == 0
	  && d_file->d_type == DT_REG)
	{
	  fd = get_fd(d_file->d_name);
	  if ((tetrimino = get_my_tetrimino(fd, &piece_info, option)) != NULL)
	    if (check_len(tetrimino, piece_info.x) == SUCCESS)
	      my_put_in_list(tet, tetrimino, d_file->d_name, piece_info);
	  free_gnl(fd);
	}
    }
  closedir(repository);
  return (SUCCESS);
}
