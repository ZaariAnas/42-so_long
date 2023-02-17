/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:10:40 by azari             #+#    #+#             */
/*   Updated: 2023/02/17 18:50:55 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_map_lines(char *map_file)
{
	int	v;
	int	fd;

	fd = open(map_file, O_RDONLY);
	v = 0;
	if (fd == -1)
		raise_error("Error\nfile access failed");
	while (get_next_line(fd))
		v++;
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
	return(map);
}

void	process_map(char **map, char *map_file)
{
	int	size;

	size = count_map_lines(map_file);
	if (check_map_shape(map, size))
		raise_error("Error:\nmap shape unvalid");
	if (check_map_walls(map, size))
		raise_error("Error:\nmap barriers unvalid");
	if (check_map_elements(map, size))
		raise_error("Error:\nmap elements unvalid");
	if (check_map_element_validity(map, size))
		raise_error("Error:\nmap elements unvalid");
}