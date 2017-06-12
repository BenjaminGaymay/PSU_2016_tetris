/*
** main.h for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 20 14:05:55 2017 Benjamin GAYMAY
** Last update Fri Mar 10 11:00:40 2017 Benjamin GAYMAY
*/

#ifndef MAIN_H_
# define MAIN_H_

#include <getopt.h>

struct option	long_option[] =
  {
    {"l", required_argument, 0, 1},
    {"kl", required_argument, 0, 2},
    {"kr", required_argument, 0, 3},
    {"kt", required_argument, 0, 4},
    {"kd", required_argument, 0, 5},
    {"kq", required_argument, 0, 6},
    {"kp", required_argument, 0, 7},
    {"w", no_argument, 0, 8},
    {"d", no_argument, 0, 9},
    {"level=", required_argument, 0, 1},
    {"key-left=", required_argument, 0, 2},
    {"key-right=", required_argument, 0, 3},
    {"key-turn=", required_argument, 0, 4},
    {"key-drop=", required_argument, 0, 5},
    {"key-quit=", required_argument, 0, 6},
    {"key-pause=", required_argument, 0, 7},
    {"without-next", no_argument, 0, 8},
    {"debug", no_argument, 0, 9},
    {"map-size=", required_argument, 0, 10},
    {"help", no_argument, 0, 11},
    {0, 0, 0, 0}
  };

#endif /* !MAIN_H_ */
