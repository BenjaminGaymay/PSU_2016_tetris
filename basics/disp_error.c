/*
** disp_error.c for disp_error in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 20 11:12:46 2017 Benjamin GAYMAY
** Last update Mon Feb 20 11:14:13 2017 Benjamin GAYMAY
*/
int	disp_error(char *s)
{
  int	i;

  i = -1;
  while (s[++i]);
  write(2, s, i);
  return (84);
}
