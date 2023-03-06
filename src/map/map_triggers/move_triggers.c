/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tiggers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:03:57 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 13:45:14 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	right_step_trigger(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x][c.y + 1] != 'E' && mlx->map[c.x][c.y + 1] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x][c.y] = '0';
		if (mlx->map[c.x][c.y + 1] == 'C')
			mlx->col_num--;
		mlx->map[c.x][c.y + 1] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x][c.y + 1] == 'E' && !mlx->col_num)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !", mlx->mv_cnt);
		mlx->map[c.x][c.y + 1] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}

void	left_step_trigger(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x][c.y - 1] != 'E' && mlx->map[c.x][c.y - 1] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x][c.y] = '0';
		if (mlx->map[c.x][c.y - 1] == 'C')
			mlx->col_num--;
		mlx->map[c.x][c.y - 1] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x][c.y - 1] == 'E' && !mlx->col_num)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !", mlx->mv_cnt);
		mlx->map[c.x][c.y - 1] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}


void	up_step_trigger(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x - 1][c.y] != 'E' && mlx->map[c.x - 1][c.y] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x][c.y] = '0';
		if (mlx->map[c.x - 1][c.y] == 'C')
			mlx->col_num--;
		mlx->map[c.x - 1][c.y] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x - 1][c.y] == 'E' && !mlx->col_num)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !", mlx->mv_cnt);
		mlx->map[c.x - 1][c.y] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}

void	down_step_trigger(t_vars *mlx, int keycode, t_coord c)
{
	if (mlx->map[c.x + 1][c.y] != 'E' && mlx->map[c.x + 1][c.y] != '1')
	{
		mlx->mv_cnt++;
		mlx->map[c.x][c.y] = '0';
		if (mlx->map[c.x + 1][c.y] == 'C')
			mlx->col_num--;
		mlx->map[c.x + 1][c.y] = 'P';
		ft_printf("moves -> %d \n", mlx->mv_cnt);
	}
	else if (mlx->map[c.x + 1][c.y] == 'E' && !mlx->col_num)
	{
		mlx->mv_cnt++;
		ft_printf("moves -> %d \n GAME OVER ..YOU WON !", mlx->mv_cnt);
		mlx->map[c.x + 1][c.y] = '0';
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}
