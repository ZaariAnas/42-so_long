/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_triggers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:49:31 by azari             #+#    #+#             */
/*   Updated: 2023/02/26 19:12:07 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	rendering_player(t_vars *mlx, int x, int y, int keycode)
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

void	rendering_exit(t_vars *mlx, int x, int y)
{
	if (mlx->col_num)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ext_c, y * 40, x * 40);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ext_o, y * 40, x * 40);
}