/*
** use_array.h for use_array in /home/benjamin.g
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Jan 19 17:52:12 2017 Benjamin GAYMAY
** Last update Wed Feb  1 13:58:04 2017 Benjamin GAYMAY
*/

#ifndef USE_ARRAY_H_
# define USE_ARRAY_H_

int	count_lines(char *buffer, char separator);
int	count_columns(char *buffer, char separator);
void	add_in_array(char **array, char *str, char separator);
char	**create_array(char *str, char separator);
void	free_array(char **array);

#endif /* !USE_ARRAY_H_ */
