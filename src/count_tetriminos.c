/*
** count_tetriminos.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Feb 24 14:24:03 2017 Benjamin GAYMAY
** Last update Tue Mar 14 16:21:24 2017 Benjamin GAYMAY
*/

#include <dirent.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

int	count_tetriminos()
{
  DIR	*repository;
  struct dirent	*d_file;
  int	i;

  if ((repository = opendir("./tetriminos")) == NULL)
    return (0);
  i = 0;
  while ((d_file = readdir(repository)) != NULL)
    {
      if (my_end_strcmp(d_file->d_name, ".tetrimino") == 0 &&
	  d_file->d_type == DT_REG)
	i++;
    }
  closedir(repository);
  return (i);
}
