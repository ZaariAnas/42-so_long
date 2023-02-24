/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_triggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:59 by azari             #+#    #+#             */
/*   Updated: 2023/02/24 17:39:36 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_key(int keyStroke, t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	exit(0);
}

void	render_map(t_vars *vars)
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
				mlx_put_image_to_window(vars->mlx, vars->win, vars->bw,
				 j * 40, i * 40);
			else if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->fs,
				 j * 40, i * 40);
			else if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->ext,
				 j * 40, i * 40);
			else if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->col,
				 j * 40, i * 40);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pl,
				 j * 40, i * 40);
		}
	}
}

void	import_map_assets(t_vars *mlx)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	mlx->bw = mlx_xpm_file_to_image(mlx->mlx, "././assets/bw.xpm", &x, &y);
	mlx->fs = mlx_xpm_file_to_image(mlx->mlx, "././assets/fs.xpm", &x, &y);
	mlx->ext = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex.xpm", &x, &y);
	mlx->col = mlx_xpm_file_to_image(mlx->mlx, "././assets/col.xpm", &x, &y);
	mlx->pl = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl.xpm", &x, &y);
}