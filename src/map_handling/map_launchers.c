/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_launchers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:19 by azari             #+#    #+#             */
/*   Updated: 2023/02/28 17:15:16 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	player_key_stroke(int keycode, t_vars *mlx)
{
	t_coord c;
	c = get_position(mlx->map, 'P');
	keystrokes_triggers(mlx, keycode, c);
	render_map(keycode, mlx);
	return (1);
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