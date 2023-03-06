/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:40 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 12:18:23 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_map_lines(char *map_file)
{
	int	v;
	int	fd;
	char *tmp;

	fd = open(map_file, O_RDONLY);
	v = 0;
	if (fd == -1)
		raise_error("Error\nfile access failed");
	tmp = get_next_line(fd);
	while (tmp)
	{
		v++;
		free(tmp);
		tmp = get_next_line(fd); 
	}
	if (!v)
		raise_error("Error\nempty map file");
	close(fd);
	return (v);
}

char	**get_map(char *map_file)
{
	int		i;
	int		fd;
	int		size;
	char	**map;

	i = -1;
	size = count_map_lines(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		raise_error("Error\nfile access failed");
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
	{
		free(map);
		raise_error("error:\nmemory allocation failure");
	}
	while (++i < size)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	return (map);
}

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

int	get_map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}