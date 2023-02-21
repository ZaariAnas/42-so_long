/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:38:55 by azari             #+#    #+#             */
/*   Updated: 2022/10/27 14:00:28 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*my_line(int fd, char *buffer, char *adv)
{
	char	*str;
	ssize_t	n;

	n = 1;
	while (n != 0 && !ft_strchr(buffer, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n] = '\0';
		str = ft_strjoin(adv, buffer);
		free(adv);
		adv = str;
	}
	free(buffer);
	return (adv);
}

static char	*full_line(char *adv)
{
	size_t	i;
	char	*rslt;

	i = 0;
	while (adv[i] && adv[i] != '\n')
		i++;
	rslt = ft_substr(adv, 0, i + 1);
	return (rslt);
}

static void	new_adv(char **x)
{
	size_t	i;
	char	*nadv;
	char	*adv;

	adv = *x;
	i = 0;
	while (adv[i] && adv[i] != '\n')
		i++;
	if (adv[i] == '\n')
		i++;
	nadv = ft_substr(adv, i, ft_strlen(adv + i));
	free(adv);
	*x = nadv;
}

char	*get_next_line(int fd)
{
	static char	*adv[10240];
	char		*buffer;
	char		*rslt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(adv[fd]);
		return (NULL);
	}
	buffer[0] = '\0';
	adv[fd] = my_line(fd, buffer, adv[fd]);
	if (!adv[fd])
		return (NULL);
	if (!*adv[fd])
	{
		free(adv[fd]);
		adv[fd] = 0;
		return (NULL);
	}
	rslt = full_line(adv[fd]);
	new_adv(&adv[fd]);
	return (rslt);
}
