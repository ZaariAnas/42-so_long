/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:01:37 by azari             #+#    #+#             */
/*   Updated: 2023/02/21 18:15:55 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int	x;
	int	y;

	x = 32;
	y = 32;
	raise_arg_error(ac, av[1]);
	vars.mlx = mlx_init();
	raise_ptr_error(vars.mlx);
	vars.map = get_map(av[1]);
	process_map(vars.map, av[1]);
	vars.map_lines = count_map_lines(av[1]);
	vars.win = mlx_new_window(vars.mlx, (ft_strlen(vars.map[0]) - 1) * 32,
								 vars.map_lines * 32, "so_long");
	raise_ptr_error(vars.win);
	vars.brick_wall = mlx_xpm_file_to_image(vars.mlx, "assets/brick_wall.xpm", &x, &y);
	put_map_to_win(&vars, 2);
	mlx_loop(vars.mlx);
	return (0);
}
