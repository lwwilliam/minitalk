/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:25:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/06/24 12:11:17 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(unsigned long args)
{
	int	i;

	i = 0;
	if (args == '0')
		return (1);
	if (args != 0)
	{
		args = args / 16;
		i++;
	}
	return (i);
}

void	ptr_address(unsigned long args, int *c)
{
	if (args >= 16)
	{
		ptr_address((args / 16), c);
		ptr_address((args % 16), c);
	}
	else
	{
		if (args <= 9)
			ft_putchar(args + '0');
		else
			ft_putchar((args - 10) + 'a');
		++*c;
	}
}
