/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyses2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:29:00 by azari             #+#    #+#             */
/*   Updated: 2023/03/09 13:11:09 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

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

int	check_map_width(t_vars *mlx)
{
	int	i;

	i = (ft_strlen(mlx->map[0]) - 1) * 40;
	if (i > 2560)
		return (1);
	return (0);
}

int	check_map_height(t_vars *mlx)
{
	int	i;

	i = mlx->map_lines * 40;
	if (i > 1440)
		return (1);
	return (0);
}
