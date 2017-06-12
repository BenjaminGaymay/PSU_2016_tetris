/*
** tetris.h for tetris in /home/benjamin.g/delivery/PSU_2016_tetris
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Feb 20 14:05:55 2017 Benjamin GAYMAY
** Last update Sun Mar 19 19:17:05 2017 Benjamin GAYMAY
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include <dirent.h>
#include "option.h"

# define ERROR 84
# define SUCCESS 0
# define FAILURE 1

typedef struct		s_tetriminos
{
  char			**form[5];
  char			*name;
  int			x;
  int			y;
  int			color;
  int			id;

  struct s_tetriminos	*next;
}			t_tetriminos;

typedef struct		s_piece
{
  int			color;
  int			x;
  int			y;
}			t_piece;

typedef struct		s_tetris
{
  int			rows;
  int			col;
  int			score;
  int			level;
  int			actual;
  int			form;
  int			timer;
  int			high;
  int			line;
  t_tetriminos		*tetriminos;
  t_tetriminos		*next;
  t_koption		option;
  char			**map;
  char			**debug_map;
}			t_tetris;

/* flags.c */
int	let_l(char *, t_koption *);
int	let_kl(char *, t_koption *);
int	let_kr(char *, t_koption *);
int	let_kt(char *, t_koption *);
int	let_kd(char *, t_koption *);
int	let_kq(char *, t_koption *);
int	let_kp(char *, t_koption *);
int	let_m(char *, t_koption *);
int	let_w(char *, t_koption *);
int	let_d(char *, t_koption *);

/* columns_and_rows.c */
int	get_rows(const char *, const char);
int	get_columns(const char *, const char);

/* debug.c */
int	show_debug_struct(t_koption *);
int	check_first_line(char *, const int, t_koption *);
int	count_tetriminos();
int	get_int(const char *);
int	check_len(char **, const int);
int	debug_tetriminos(t_koption *);
int	press_any_key();
int	show_debug_struct(t_koption *);
void	ascii_order(char **);
int	aff_tetriminos(char **, t_koption *);
int	get_tetriminos_name(DIR *, char **);

/* main.c */
int	disp_help(char **);
int	disp_error();
int	check_sequences(t_koption *);
int	check_arg(int, char **);
int	check_flag(t_koption *, const int);

/* tetris.c */
int	launch_tetris(t_koption *);
int	check_put_tetrimino(t_tetris *);
int	check_fall_end(t_tetris *);
void	line_complete(t_tetris *);
void	fill_empty_map(char **, const int, const int);

/* tetriminos.c */
int	put_tetriminos_in_list(t_tetriminos **, t_koption *);
void	my_r_space(char **);
char	**get_next_form(char **);
char	**get_my_tetrimino(int fd, t_piece *, t_koption *);

/* put_tetriminos.c */
t_tetriminos	*rand_tetrimino(const t_tetris);
int	can_put_tetrimino_in_map(t_tetris *, t_tetriminos *, int, const int);
int	put_tetrimino_in_map(t_tetris *, t_tetriminos *, int, const int);

/* delete.c */
void	delete_tetrimino(t_tetris *, int *, int *);
void	my_delete_line(t_tetris *, int);

/* fall.c */
int	drop(t_tetris *);
int	fall(t_tetris);

/* moves.c */
void	turn(t_tetris *);
void	move_left(t_tetris);
void	move_right(t_tetris);

/* print_map.c */
void	aff_term(t_tetris, int, int);
void	print_my_map(const t_tetris, const int, const int);

/* colors.c */
void	my_init_color();
int	my_rand(int, int);
int	lose_one();

/* ncurses.c */
void	create_term(t_koption *, t_tetris *);

/* score.c */
void	put_high(t_tetris *);
int	get_high(t_tetris *);

/* pimp.c */
void	snake();
void	aff_lose();
void	print_diag(int, int);
/* option.h */
int	init_option(t_koption *, char **);

/* read.c */
char	*my_read(int, int, int);

#endif /* !TETRIS_H_ */
