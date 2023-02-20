/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:10:10 by azari             #+#    #+#             */
/*   Updated: 2023/02/20 15:29:35 by azari            ###   ########.fr       */
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

char	**flood_fill_map(char **map, int x, int y, char start, char end)
{
	if (map[x][y] == 'C' || map[x][y] == 'P')
		map[x][y] = '0';

	if (map[x][y] == '0')
	{
		map[x][y] == 'W';
     	flood_fill_map(map, x - 1, y, start, end);
     	flood_fill_map(map, x + 1, y, start, end);
     	flood_fill_map(map, x, y - 1, start, end);
     	flood_fill_map(map, x, y + 1, start, end);
	}
	return (map);
}

//https://www.youtube.com/watch?v=b5HmdWRqyOg&list=RDMM&start_radio=1&rv=G7KNmW9a75Y


// char	**dup_map(char **map)
// {
// 	int		i;
// 	int		fd;
// 	int		size;
// 	char	**map_dup;

// 	i = -1;
// 	size = get_map_size(map);
// 	map_dup = (char **)malloc(sizeof(char *) * (size + 1));
// 	if (!map_dup)
// 	{
// 		free(map_dup);
// 		raise_error("error:\nmemory allocation failure");
// 	}
// 	while (++i < size)
// 		map_dup[i] = get_next_line(fd);
// 	map_dup[i] = NULL;
// 	return (map_dup);
// }

// int	get_map_size(char **map)
// {
// 	int	i;

// 	i = -1;
// 	while (map[i])
// 		i++;
// 	return (i);
// }

