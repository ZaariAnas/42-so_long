/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:10:10 by azari             #+#    #+#             */
/*   Updated: 2023/02/20 19:22:34 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_occurence(char c, char **map, int size)
{
	int	i;
	int	j;
	int	occur;
	int	norm;

	i = -1;
	occur = 0;
	norm = ft_strlen(map[0]) - 1;
	while (++i < size)
	{
		j = -1;
		while (++j < norm - 1)
		{
			if (map[i][j] == c)
				occur++;
		}
	}
	return (occur);
}

int	check_map_element_validity(char **map, int size)
{
	int	check;

	check = get_occurence('E', map, size);
	if (check != 1)
		return (1);
	check = get_occurence('C', map, size);
	if (check < 1)
		return (1);
	check = get_occurence('P', map, size);
	if (check != 1)
		return (1);
	return (0);
}

char	**flood_fill_map(char **map, int x, int y)
{
	if (map[x][y] == 'C' || map[x][y] == 'P')
		map[x][y] = '0';

	if (map[x][y] == '0')
	{
		map[x][y] = '*';
     	flood_fill_map(map, x - 1, y);
     	flood_fill_map(map, x + 1, y);
     	flood_fill_map(map, x, y - 1);
     	flood_fill_map(map, x, y + 1);
	}
	return (map);
}

char	**dup_map(char **map)
{
	char	**dup;
	int		size;
	int		i;

	i = -1;
	size = get_map_size(map);
	dup = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	while (map[++i])
		dup[i] = strdup(map[i]);
	dup[i] = NULL;
	return (dup);
}

int	check_valid_path_exit(char **map)
{
	char	**dup;
	int		*pos;
	int		x;
	int		y;

	dup = dup_map(map);
	pos = get_position(map, 'P');
	dup = flood_fill_map(dup, pos[0], pos[1]);
	pos = get_position(map, 'E');
	x = pos[0];
	y = pos[1];
	if (dup[x + 1][y] == '*' || dup[x - 1][y] == '*'
		|| dup[x][y + 1] == '*' || dup[x][y - 1] == '*')
		return (1);
	return (0);
}

