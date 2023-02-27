/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_triggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:59 by azari             #+#    #+#             */
/*   Updated: 2023/02/27 16:43:54 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	esc_key(int keyStroke, t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	exit(0);
}

void	rendering_map(int keycode, t_vars *vars)
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
				rendering_exit(&vars, x, y);
			else if (vars->map[x][y] == 'C')
				render_collectible(&vars, x, y);
			else
				rendering_player(&vars, x, y, keycode);
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
	mlx->col1 = mlx_xpm_file_to_image(mlx->mlx, "././assets/col1.xpm", &x, &y);
	mlx->col2 = mlx_xpm_file_to_image(mlx->mlx, "././assets/col2.xpm", &x, &y);
	mlx->col3 = mlx_xpm_file_to_image(mlx->mlx, "././assets/col3.xpm", &x, &y);
	mlx->ext_c = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex.xpm", &x, &y);
	mlx->ext_o = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex.xpm", &x, &y);
	mlx->pl_p = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_p.xpm", &x, &y);
	mlx->pl_b = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_b.xpm", &x, &y);
	mlx->pl_l = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_l.xpm", &x, &y);
	mlx->pl_r = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_r.xpm", &x, &y);
}

void	keystrokes_triggers(t_vars *mlx, int keycode, t_coord t)
{
	if  (keycode == 2 || keycode == 124)
		trigger_step_right(&mlx, keycode, t); // function to make ------------------
	else if  (keycode == 0 || keycode == 123)
		trigger_step_left(&mlx, keycode, t);// function to make ------------------
	else if  (keycode == 13 || keycode == 126)
		trigger_step_up(&mlx , keycode, t);// function to make ------------------
	else if  (keycode == 1 || keycode == 125)
		trigger_step_down(&mlx, keycode, t);// function to make
	else if (keycode == 53)
	{
		ft_printf("GAME QUIT !\n");
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}