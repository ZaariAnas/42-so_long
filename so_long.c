/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:01:37 by azari             #+#    #+#             */
/*   Updated: 2023/02/15 12:08:00 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	raise_arg_error(ac, av[1]);
	vars.mlx = mlx_init();
	raise_ptr_error(vars.mlx);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, SO_LONG);
	raise_ptr_error(vars.win);
	mlx_loop(vars.mlx);
	return (0);
}
