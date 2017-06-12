/*
** my_strcmp.c for my_strcmp in /home/benjamin.g/delivery/CPool_Day06
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Oct 10 17:22:02 2016 Benjamin GAYMAY
** Last update Mon Feb 20 14:07:17 2017 Benjamin GAYMAY
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}
