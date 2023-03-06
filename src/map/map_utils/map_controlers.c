/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:28:10 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 20:16:42 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	count_map_lines(char *map_file)
{
	int		v;
	int		fd;
	char	*tmp;

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

int	get_map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	count_collec(t_vars *mlx, int size)
{
	int	i;
	int	j;
	int	norm;

	i = -1;
	norm = ft_strlen(mlx->map[0]) - 1;
	while (++i < size)
	{
		j = -1;
		while (++j < norm - 1)
		{
			if (mlx->map[i][j] == 'C')
				mlx->col_num++;
		}
	}
	return (mlx->col_num);
}
