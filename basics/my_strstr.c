/*
** my_strstr.c for my_strstr in /home/benjamin.g/delivery/CPool_Day06
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Oct 10 12:32:01 2016 Benjamin GAYMAY
** Last update Tue Mar 14 15:25:50 2017 Benjamin GAYMAY
*/

int	my_strstr(const char *s1, const char *s2)
{
  int	a;
  int	b;

  a = 0;
  while (s1[a])
    {
      b = 0;
      if (s1[a] == s2[b])
	{
	  while (s1[a] == s2[b] && s2[b] && s1[a])
	    {
	      ++a;
	      ++b;
	    }
	  if (s2[b] == '\0')
	    return (0);
	}
      ++a;
    }
  return (1);
}
