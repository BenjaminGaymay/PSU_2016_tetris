/*
** my_end_strncmp.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Sun Feb 26 15:42:04 2017 Benjamin GAYMAY
** Last update Sun Feb 26 15:45:18 2017 Benjamin GAYMAY
*/

#include "my.h"

int	my_end_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;

  if ((i = my_strlen(s1) - 1) < (j = my_strlen(s2) - 1))
    return (-1);
  while (s1[i] == s2[j] && i >= 0 && j >= 1)
    {
      i--;
      j--;
    }
  return (s1[i] - s2[j]);
}
