/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:32:30 by lwilliam          #+#    #+#             */
/*   Updated: 2022/06/23 21:52:31 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_check(char const *type, va_list args, int x)
{
	int	c;

	c = 0;
	if (type[x] == 'c')
		c = ft_putchar(va_arg(args, int));
	if (type[x] == 's')
		c = ft_putstr(va_arg(args, char *));
	if (type[x] == 'p')
	{
		c += write(1, "0x", 2);
		ptr_address(va_arg(args, unsigned long), &c);
	}
	if (type[x] == 'd' || type[x] == 'i')
		ft_putnbr(va_arg(args, int), &c);
	if (type[x] == 'u')
		unsigned_int(va_arg(args, unsigned int), &c);
	if (type[x] == 'x')
		bx_or_sx(va_arg(args, int), 'x', &c);
	if (type[x] == 'X')
		bx_or_sx(va_arg(args, int), 'X', &c);
	if (type[x] == '%')
		c += write(1, "%", 1);
	return (c);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		len;
	int		x;

	va_start (args, type);
	x = 0;
	len = 0;
	while (type[x])
	{
		if (type[x] == '%')
		{
			x++;
			len += type_check(type, args, x);
		}
		else
			len += write(1, &type[x], 1);
		x++;
	}
	va_end(args);
	return (len);
}
