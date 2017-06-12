/*
** read.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Mar 14 09:33:56 2017 Benjamin GAYMAY
** Last update Wed Mar 15 16:44:58 2017 Benjamin GAYMAY
*/

#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "tetris.h"
#include "my.h"

char	*clear_str(char *str, int *i)
{
  int	a;

  a = 0;
  while (a <= 200)
    str[a++] = '\0';
  *i = 0;
  return (str);
}

char			*my_read(int reset, int on, int off)
{
  struct termios	old_t;
  struct termios	new_t;
  static char		s[200];
  static int		i = 0;
  int			j;

  if (i == 200 || reset == 1)
    return (clear_str(s, &i));
  if ((ioctl(0, TCGETS, &old_t)) == -1)
    return (NULL);
  new_t = old_t;
  new_t.c_lflag &= ~ECHO;
  new_t.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &new_t);
  ioctl(0, FIONBIO, &on);
  j = read(0, &s[i], 1);
  ioctl(0, FIONBIO, &off);
  if (j == -1)
    {
      ioctl(0, TCSETS, &old_t);
      return (NULL);
    }
  ioctl(0, TCSETS, &old_t);
  s[i = i + j] = '\0';
  return (s);
}
