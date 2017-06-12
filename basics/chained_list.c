/*
** chained_list.c for chained_list in /home/benjamin.g/save/test
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 24 19:01:02 2017 Benjamin GAYMAY
** Last update Wed Mar  8 11:39:36 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"
#include "my_printf.h"

int		my_put_in_list(t_tetriminos **list, char **f1,
			       char *n, t_piece info)
{
  t_tetriminos	*element;
  static int	id = 0;

  if ((element = malloc(sizeof(*element))) == NULL)
    return (ERROR);
  element->form[0] = f1;
  element->form[1] = get_next_form(f1);
  element->form[2] = get_next_form(element->form[1]);
  element->form[3] = get_next_form(element->form[2]);
  element->form[4] = NULL;
  element->name = n;
  element->color = info.color;
  element->x = info.x;
  element->y = info.y;
  element->next = *list;
  element->id = id;
  id += 1;
  *list = element;
  return (SUCCESS);
}

void		my_show_list(t_tetriminos *list)
{
  t_tetriminos	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putstr("\nform1:\n");
      my_showtab(tmp->form[0]);
      my_putstr("form2:\n");
      my_showtab(tmp->form[1]);
      my_putstr("form3:\n");
      my_showtab(tmp->form[2]);
      my_putstr("form4:\n");
      my_showtab(tmp->form[3]);
      my_putstr("color: ");
      my_printf("%d", tmp->color);
      my_putstr("\nx: ");
      my_printf("%d", tmp->x);
      my_putstr("\ny: ");
      my_printf("%d", tmp->y);
      tmp = tmp->next;
    }
}

int		my_len_list(t_tetriminos *list)
{
  t_tetriminos	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
