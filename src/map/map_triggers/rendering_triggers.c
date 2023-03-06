/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_triggers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:59 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 13:47:19 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	render_map(int keycode, t_vars *vars)
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
				render_exit(vars, x, y);
			else if (vars->map[x][y] == 'C')
				render_collectibles(vars, x, y);
			else
				render_player(vars, x, y, keycode);
		}
	}
}

void	render_player(t_vars *mlx, int x, int y, int keycode)
{
	if (keycode == 2 || keycode == 124)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_r, y * 40, x * 40);
	else if(keycode == 0 || keycode == 123)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_l, y * 40, x * 40);
	else if (keycode == 1 || keycode == 125)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_u, y * 40, x * 40);
	else if (keycode == 13 || keycode == 126)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_d, y * 40, x * 40);
}

void	render_exit(t_vars *mlx, int x, int y)
{
	if (mlx->col_num)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ext_c, y * 40, x * 40);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ext_o, y * 40, x * 40);
}

void	render_collectibles(t_vars *mlx, int x, int y)
{
	static int	c;

	c = 0;
	if (x == 3)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->col3, y * 40, x * 40);
		c = 2;
	}
	else if (c == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->col2, y * 40, x * 40);
		c = 1;
	}
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->col1, y * 40, x * 40);
		c = 3;	
	}
}
