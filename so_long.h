/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:56:37 by azari             #+#    #+#             */
/*   Updated: 2023/02/28 17:18:23 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define SO_LONG "Collect and Evade"

typedef struct s_coordinations{
	int	x;
	int	y;
}			t_coord;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*bw;
	void	*fs;
	void	*col1;
	void	*col2;
	void	*col3;
	void	*pl;
	void	*pl_r;
	void	*pl_l;
	void	*pl_u;
	void	*pl_d;
	void	*ext_o;
	void	*ext_c;
	char	**map;
	int		col_num;
	int		mv_cnt;
	int		map_lines;
	int		exit_state;
}				t_vars;

t_coord	get_position(char **map, char c);
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
int		get_occurence(char c, char **map, int size);
int		check_map_element_validity(char **map, int size);
char	**flood_fill_map(char **map, int x, int y);
char	**dup_map(char **map);
int		check_valid_path_exit(char **map);
int		get_map_size(char **map);
int		check_valid_path_col(char **map);
void	import_map_assets(t_vars *mlx);
void	render_map(int keycode, t_vars *vars);
void	render_player(t_vars *mlx, int x, int y, int keycode);
void	render_exit(t_vars *mlx, int x, int y);
void	render_collectibles(t_vars *mlx, int x, int y);
void	right_step_trigger(t_vars *mlx, int keycode, t_coord c);
void	left_step_trigger(t_vars *mlx, int keycode, t_coord c);
void	down_step_trigger(t_vars *mlx, int keycode, t_coord c);
void	up_step_trigger(t_vars *mlx, int keycode, t_coord c);
int		player_key_stroke(int keycode,t_vars *mlx);
void	keystrokes_triggers(t_vars *mlx, int keycode, t_coord t);
int		count_collec(t_vars *mlx, int size);

#endif