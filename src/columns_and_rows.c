/*
** columns_and_rows.c for tetris in /home/benjamin.g/delivery/PSU_2016_tetris/src
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Mar  6 20:54:04 2017 Benjamin GAYMAY
** Last update Mon Mar 13 12:47:18 2017 Benjamin GAYMAY
*/

int	get_rows(const char *s, const char separator)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (s[i] != separator && s[i] != '\0')
    nb = nb * 10 + s[i++] - '0';
  if (s[i] == '\0')
    nb = 0;
  return (nb);
}

int	get_columns(const char *s, const char separator)
{
  int	i;
  int	nb;

  i = 0;
  while (s[i] != separator && s[i] != '\0')
    i++;
  if (s[i] == '\0')
    return (0);
  nb = 0;
  while (s[++i] != '\0')
    nb = nb * 10 + s[i] - '0';
  return (nb);
}
