/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controlers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:10:10 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 13:58:09 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

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

int	check_in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

t_coord	get_position(char **map, char c)
{
	t_coord	pnt;
	int		i;
	int		j;
	int		size;

	i = -1;
	size = get_map_size(map);
	while (++i < size)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				pnt.x = i;
				pnt.y = j;
				return (pnt);
			}
		}
	}
	return (pnt);
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
		dup[i] = ft_strdup(map[i]);
	dup[i] = NULL;
	return (dup);
}
