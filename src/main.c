/*
** main.c for emacs in /home/BISHOP/delivery/PSU_2016_tetris/src
**
** Made by enzo petitpierre
** Login   <BISHOP@epitech.net>
**
** Started on  Mon Feb 20 11:12:50 2017 enzo petitpierre
** Last update Sun Mar 19 19:16:35 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "my.h"
#include "main.h"
#include "tetris.h"
#include "my_printf.h"
#include "my_fprintf.h"

int	check_arg(int ac, char **av)
{
  int	i;

  i = 1;
  while (i != ac)
    {
      if (av[i][0] != '-' && av[i - 1][0] != '-' )
	return (FAILURE);
      i++;
    }
  return (SUCCESS);
}

int	check_flag(t_koption *option, const int ret)
{
  if (check_sequences(option) != SUCCESS)
    return (ERROR);
  if (ret != SUCCESS)
    return (ERROR);
  if (my_strcmp(option->debug, "true") == 0)
    show_debug_struct(option);
  return (SUCCESS);
}

static int	let_h(char *s, t_koption *option)
{
  s = s;
  option->help = "true\0";
  return (SUCCESS);
}

static int	(*set_opt[13])(char *optarg, t_koption *option) =
{
  let_l,
  let_kl,
  let_kr,
  let_kt,
  let_kd,
  let_kq,
  let_kp,
  let_w,
  let_d,
  let_m,
  let_h
};

int		main(int ac, char **av, char **envp)
{
  t_koption	option;
  int		c;
  int		x;
  int		ret;

  ret = 0;
  if (check_arg(ac, av) == FAILURE)
    return (disp_help(av));
  if (init_option(&option, envp) == ERROR)
    return (disp_error());
  while ((c = getopt_long_only(ac, av, "", long_option, &x)) != -1)
    {
      if (c > 0 && c < 13)
	{
	  if (set_opt[c - 1](optarg, &option) == FAILURE)
	    ret++;
	}
      else
	return (disp_help(av));
    }
  if (my_strcmp(option.help, "true") == 0)
    return (disp_help(av));
  if (check_flag(&option, ret) != SUCCESS)
    return (disp_error());
  return (launch_tetris(&option) != SUCCESS ? disp_error() : SUCCESS);
}
