/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:09:23 by azari             #+#    #+#             */
/*   Updated: 2023/02/21 16:57:36 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	raise_ptr_error(void *ptr)
{
	if (!ptr)
	{
		perror("error");
		exit(0);
	}
}

void	raise_error(char *str)
{
	perror(str);
	exit(0);
}

void	raise_arg_error(int nbr, char *map)
{
	int		start;
	char	*ext;

	if (nbr != 2)
		raise_error("error:\nunvalid arguments");
	start = ft_strlen(map) - 4;
	ext = ft_substr(map, start, 4);
	if (ft_strcmp(".ber", ext))
	{
		free(ext);
		raise_error("error:\nunvalid map file");
	}
	free(ext);
}