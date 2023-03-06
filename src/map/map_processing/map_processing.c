/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:40 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 20:09:37 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	process_map(char **map, char *map_file)
{
	int	size;

	size = count_map_lines(map_file);
	if (check_map_shape(map, size))
		raise_error("Error\nmap shape unvalid");
	if (check_map_walls(map, size))
		raise_error("Error\nmap barriers unvalid");
	if (check_map_elements(map, size))
		raise_error("Error\nmap elements unvalid");
	if (check_map_element_validity(map, size))
		raise_error("Error\nmap elements unvalid");
	if (!check_valid_path_exit(map))
		raise_error("Error\nmap conflict :: no valid path to exit");
	if (!check_valid_path_col(map))
		raise_error("Error\nmap conflict :: no valid path to collectibles");
}

int	player_key_stroke(int keycode, t_vars *mlx)
{
	t_coord	c;

	c = get_position(mlx->map, 'P');
	keystrokes_triggers(mlx, keycode, c);
	render_map(keycode, mlx);
	return (1);
}
