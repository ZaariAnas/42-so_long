/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_triggers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:49:31 by azari             #+#    #+#             */
/*   Updated: 2023/02/27 14:09:23 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_player(t_vars *mlx, int x, int y, int keycode)
{
	if (keycode == 2 || keycode == 124)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_r, y * 40, x * 40);
	else if(keycode == 0 || keycode == 123)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_l, y * 40, x * 40);
	else if (keycode == 1 || keycode == 125)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_p, y * 40, x * 40);
	else if (keycode == 13 || keycode == 126)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl_b, y * 40, x * 40);
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
	static int	x;

	x = 0;
	if (x = 3)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->col3, y * 40, x * 40);
		x = 2;
	}
	else if (x = 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->col2, y * 40, x * 40);
		x = 1;
	}
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->col1, y * 40, x * 40);
		x = 3;	
	}
}

