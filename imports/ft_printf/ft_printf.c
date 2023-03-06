/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:05:42 by azari             #+#    #+#             */
/*   Updated: 2023/02/28 16:06:34 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(va_list ptr, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putnbr_base_u((unsigned long long)va_arg(ptr, void *), B16L);
	}
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_base_s(va_arg(ptr, int), B10);
	else if (c == 'u')
		i += ft_putnbr_base_u(va_arg(ptr, unsigned int), B10);
	else if (c == 'x')
		i += ft_putnbr_base_u(va_arg(ptr, unsigned int), B16L);
	else if (c == 'X')
		i += ft_putnbr_base_u(va_arg(ptr, unsigned int), B16U);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		read;
	int		i;

	read = 0;
	i = -1;
	va_start(ptr, s);
	while (s[++i])
	{
		if (s[i] != '%')
			read += ft_putchar(s[i]);
		if (read < 0)
			return (-1);
		else if (s[i] == '%' && s[i + 1])
		{
			read += ft_convert(ptr, s[i + 1]);
			if (read < 0)
				return (-1);
			i++;
		}
	}
	va_end(ptr);
	return (read);
}
