/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tiggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:03:57 by azari             #+#    #+#             */
/*   Updated: 2023/02/27 16:57:30 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	trigger_step_right(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x, c.y + 1] != 'E' && mlx->map[c.x, c.y + 1] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x, c.y] = '0';
		if (mlx->map[c.x, c.y + 1] == 'C')
			mlx->col_num--;
		mlx->map[c.x, c.y + 1] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x, c.y + 1] == 'E' && !mlx->mv_cnt)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !");
		mlx->map[c.x, c.y + 1] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}

void	trigger_step_left(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x, c.y - 1] != 'E' && mlx->map[c.x, c.y - 1] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x, c.y] = '0';
		if (mlx->map[c.x, c.y - 1] == 'C')
			mlx->col_num--;
		mlx->map[c.x, c.y - 1] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x, c.y - 1] == 'E' && !mlx->mv_cnt)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !");
		mlx->map[c.x, c.y - 1] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}


void	trigger_step_down(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x - 1, c.y] != 'E' && mlx->map[c.x - 1, c.y] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x, c.y] = '0';
		if (mlx->map[c.x - 1, c.y] == 'C')
			mlx->col_num--;
		mlx->map[c.x - 1, c.y] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x - 1, c.y] == 'E' && !mlx->mv_cnt)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !");
		mlx->map[c.x - 1, c.y] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}

void	trigger_step_up(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x + 1, c.y] != 'E' && mlx->map[c.x + 1, c.y] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x, c.y] = '0';
		if (mlx->map[c.x + 1, c.y] == 'C')
			mlx->col_num--;
		mlx->map[c.x + 1, c.y] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x + 1, c.y] == 'E' && !mlx->mv_cnt)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !");
		mlx->map[c.x + 1, c.y] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}
