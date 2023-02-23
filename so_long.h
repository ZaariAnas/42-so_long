/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:56:37 by azari             #+#    #+#             */
/*   Updated: 2023/02/21 17:44:41 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define SO_LONG "Collect and Evade"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	int		map_lines;
	char	**map;
	void	*brick_wall;
}				t_vars;

void	raise_ptr_error(void *ptr);
void	raise_arg_error(int nbr, char *map);
void	raise_error(char *str);
int		esc_key(int keyStroke, t_vars *var);
int		ft_strcmp(char *s1, char *s2);
char	**get_map(char *map_file);
void	process_map(char **map, char *map_file);
int		count_map_lines(char *map_file);
int		check_map_walls(char **map, int size);
int		check_map_shape(char **map, int size);
int		check_map_elements(char **map, int size);
int		check_map_element_validity(char **map, int size);
int		check_in_set(char c, char *set);
int		*get_position(char **map, char c);
int		get_occurence(char c, char **map, int size);
int		check_map_element_validity(char **map, int size);
char	**flood_fill_map(char **map, int x, int y);
char	**dup_map(char **map);
int		check_valid_path_exit(char **map);
int		get_map_size(char **map);
int		check_valid_path_col(char **map);
void	put_map_to_win(t_vars *vars, int keycode);

#endif