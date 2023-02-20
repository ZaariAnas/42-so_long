/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:29:00 by azari             #+#    #+#             */
/*   Updated: 2023/02/20 15:29:26 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_map_shape(char **map, int size)
{
	int		i;
	size_t	norm;

	i = -1;
	norm = ft_strlen(map[++i]);
	while (++i < size)
	{
		if (i == (size - 1))
			norm--;
		if (ft_strlen(map[i]) != norm)
			return (1);
	}
	return (0);
}

int	check_map_walls(char **map, int size)
{
	int	i;
	int	j;
	int	norm;

	i = -1;
	norm = ft_strlen(map[0]) - 1;
	while (++i < size)
	{
		if (i == 0 || i == (size - 1))
		{
			j = -1;
			while (++j < norm)
			{
				if (map[i][j] != '1')
					return (1);
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][norm - 1] != '1')
				return (1);
		}
	}
	return (0);
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

int	check_map_elements(char **map, int size)
{
	int	i;
	int	j;
	int	norm;

	i = -1;
	norm = ft_strlen(map[0]);
	while (++i < size)
	{
		j = -1;
		while (++j < norm - 1)
		{
			if (!check_in_set(map[i][j], "01CEP"))
				return (1);
		}
	}
	return (0);
}

