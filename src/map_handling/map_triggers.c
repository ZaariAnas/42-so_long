/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_triggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:59 by azari             #+#    #+#             */
/*   Updated: 2023/02/28 19:09:41 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_key(int keyStroke, t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	exit(0);
}

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

void	import_map_assets(t_vars *mlx)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	mlx->bw = mlx_xpm_file_to_image(mlx->mlx, "././assets/bw.xpm", &x, &y);
	mlx->fs = mlx_xpm_file_to_image(mlx->mlx, "././assets/fs.xpm", &x, &y);
	mlx->col1 = mlx_xpm_file_to_image(mlx->mlx, "././assets/col.xpm", &x, &y);
	mlx->col2 = mlx_xpm_file_to_image(mlx->mlx, "././assets/col.xpm", &x, &y);
	mlx->col3 = mlx_xpm_file_to_image(mlx->mlx, "././assets/col.xpm", &x, &y);
	mlx->ext_c = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex_c.xpm", &x, &y);
	mlx->ext_o = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex_o.xpm", &x, &y);
	mlx->pl_d = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_u.xpm", &x, &y);
	mlx->pl_u = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_d.xpm", &x, &y);
	mlx->pl_l = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_l.xpm", &x, &y);
	mlx->pl_r = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_r.xpm", &x, &y);
}

void	keystrokes_triggers(t_vars *mlx, int keycode, t_coord t)
{
	if  (keycode == 2 || keycode == 124)
		right_step_trigger(mlx, keycode, t);
	else if  (keycode == 0 || keycode == 123)
		left_step_trigger(mlx, keycode, t);
	else if  (keycode == 13 || keycode == 126)
		up_step_trigger(mlx , keycode, t);
	else if  (keycode == 1 || keycode == 125)
		down_step_trigger(mlx, keycode, t);
	else if (keycode == 53)
	{
		ft_printf("GAME QUIT !\n");
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}
