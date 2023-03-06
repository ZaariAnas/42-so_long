/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_triggers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:49:31 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 20:11:17 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	esc_key(int keyStroke, t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	exit(0);
}

void	keystrokes_triggers(t_vars *mlx, int keycode, t_coord t)
{
	if (keycode == 2 || keycode == 124)
		right_step_trigger(mlx, keycode, t);
	else if (keycode == 0 || keycode == 123)
		left_step_trigger(mlx, keycode, t);
	else if (keycode == 13 || keycode == 126)
		up_step_trigger(mlx, keycode, t);
	else if (keycode == 1 || keycode == 125)
		down_step_trigger(mlx, keycode, t);
	else if (keycode == 53)
	{
		ft_printf("GAME QUIT !\n");
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(-1);
	}
}
