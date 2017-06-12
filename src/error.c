/*
** error.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sun Mar 19 19:13:56 2017 Benjamin GAYMAY
** Last update Sun Mar 19 19:17:07 2017 Benjamin GAYMAY
*/
#include <fcntl.h>
#include <stdlib.h>
#include "tetris.h"
#include "my_printf.h"
#include "my_fprintf.h"
#include "get_next_line.h"

int	disp_error()
{
  my_fprintf("Error\n");
  return (ERROR);
}

int	disp_help(char **av)
{
  char		*s;
  int		fd;

  if ((fd = open("help", O_RDONLY)) == -1)
    return (ERROR);
  my_printf("Usage: %s [options]\n", av[0]);
  while ((s = get_next_line(fd)))
    {
      my_printf("%s\n", s);
      free(s);
    }
  return (ERROR);
}
