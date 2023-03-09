/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_triggers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:35:10 by azari             #+#    #+#             */
/*   Updated: 2023/03/06 20:44:38 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	import_map_assets(t_vars *mlx)
{
	int	x;
	int	y;

	mlx->bw = mlx_xpm_file_to_image(mlx->mlx, "././assets/bw.xpm", &x, &y);
	raise_ptr_error(mlx->bw);
	mlx->fs = mlx_xpm_file_to_image(mlx->mlx, "././assets/fs.xpm", &x, &y);
	raise_ptr_error(mlx->fs);
	mlx->col = mlx_xpm_file_to_image(mlx->mlx, "././assets/col.xpm", &x, &y);
	raise_ptr_error(mlx->col);
	mlx->ext_c = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex_c.xpm", &x, &y);
	raise_ptr_error(mlx->ext_c);
	mlx->ext_o = mlx_xpm_file_to_image(mlx->mlx, "././assets/ex_o.xpm", &x, &y);
	raise_ptr_error(mlx->ext_o);
	mlx->pl_d = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_u.xpm", &x, &y);
	raise_ptr_error(mlx->pl_d);
	mlx->pl_u = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_d.xpm", &x, &y);
	raise_ptr_error(mlx->pl_u);
	mlx->pl_l = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_l.xpm", &x, &y);
	raise_ptr_error(mlx->pl_l);
	mlx->pl_r = mlx_xpm_file_to_image(mlx->mlx, "././assets/pl_r.xpm", &x, &y);
	raise_ptr_error(mlx->pl_r);
}
