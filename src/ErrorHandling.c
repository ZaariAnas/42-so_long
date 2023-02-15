/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:09:23 by azari             #+#    #+#             */
/*   Updated: 2023/02/15 12:01:05 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	raise_arg_error(int nbr, char *map)
{
	int		start;
	char	*ext;

	if (nbr != 2)
	{
		perror("unvalid args");
		exit(0);
	}
	start = ft_strlen(map) - 4;
	ext = ft_substr(map, start, 4);
	if (ft_strcmp(".ber", ext))
	{
		perror("map file unvalid ()");
		free(ext);
		exit(0);
	}
	free(ext);
}
