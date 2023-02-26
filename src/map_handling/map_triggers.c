/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_triggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:59 by azari             #+#    #+#             */
/*   Updated: 2023/02/26 19:07:50 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_key(int keyStroke, t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	exit(0);
}

void	rendering_map(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	while (vars->map[++x])
	{
		y = -1;
		while (vars->map[x][++y])
		{
			if (vars->map[x][y] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->bw,
				 y * 40, x * 40);
			else if (vars->map[x][y] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->fs,
				 y * 40, x * 40);
			else if (vars->map[x][y] == 'E')
				render
			else if (vars->map[x][y] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->col,
				 y * 40, x * 40);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pl,
				 y * 40, x * 40);
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
	mlx->col = mlx_xpm_file_to_image(mlx->mlx, "././assets/col.xpm", &x, &y);
	mlx->ext_c = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex.xpm", &x, &y);
	mlx->ext_o = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex.xpm", &x, &y);
	mlx->pl_p = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_p.xpm", &x, &y);
	mlx->pl_b = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_b.xpm", &x, &y);
	mlx->pl_l = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_l.xpm", &x, &y);
	mlx->pl_r = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_r.xpm", &x, &y);
}