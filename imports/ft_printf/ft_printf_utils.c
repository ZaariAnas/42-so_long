/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:06:09 by azari             #+#    #+#             */
/*   Updated: 2023/02/28 16:14:47 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_pf(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	int	i;

	i = write(1, &c, 1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen_pf(s);
	write(1, s, i);
	if (i < 0)
		return (-1);
	return (i);
}

int	ft_putnbr_base_s(long long nbr, char *base)
{
	int	read;

	read = 0;
	if (nbr < 0)
	{
		read += ft_putchar('-');
		nbr *= -1;
	}
	read += ft_putnbr_base_u(nbr, base);
	if (read < 0)
		return (-1);
	return (read);
}

int	ft_putnbr_base_u(unsigned long long nbr, char *base)
{
	unsigned long long	lenbase;
	int					read;

	lenbase = ft_strlen_pf(base);
	read = 0;
	if (nbr >= lenbase)
		read += ft_putnbr_base_u(nbr / lenbase, base);
	read += write(1, &base[nbr % lenbase], 1);
	return (read);
}
