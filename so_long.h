/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:56:37 by azari             #+#    #+#             */
/*   Updated: 2023/02/15 17:31:46 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define SO_LONG "Collect and Evade"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	raise_ptr_error(void *ptr);
void	raise_arg_error(int nbr, char *map);
int		esc_key(int keyStroke, t_vars *var);
int		ft_strcmp(char *s1, char *s2);

#endif