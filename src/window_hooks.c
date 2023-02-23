/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:59 by azari             #+#    #+#             */
/*   Updated: 2023/02/21 17:44:25 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	esc_key(int keyStroke, t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	exit(0);
}

void	put_map_to_win(t_vars *vars, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->brick_wall, j * 32, i * 32);
		}
	}
}

