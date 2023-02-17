/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:10:10 by azari             #+#    #+#             */
/*   Updated: 2023/02/17 19:09:00 by azari            ###   ########.fr       */
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
