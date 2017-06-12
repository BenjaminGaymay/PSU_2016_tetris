/*
** tetris.h for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 20 14:05:55 2017 Benjamin GAYMAY
** Last update Tue Mar 14 09:53:23 2017 Benjamin GAYMAY
*/

#ifndef OPTION_H_
# define OPTION_H_

typedef struct	s_koption
{
  char		*level;
  char		*keyleft;
  char		*keyright;
  char		*key_turn;
  char		*key_drop;
  char		*key_quit;
  char		*key_pause;
  char		*map_size;
  char		*w_next;
  char		*debug;
  char		*help;
  char		*term;
}		t_koption;

#endif /* !OPTION_H_ */
