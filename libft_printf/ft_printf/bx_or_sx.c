/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bx_or_sx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:57:51 by lwilliam          #+#    #+#             */
/*   Updated: 2022/06/23 13:05:58 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bx_or_sx(unsigned int args, char type, int *c)
{
	if (args >= 16)
	{
		bx_or_sx(args / 16, type, c);
		bx_or_sx(args % 16, type, c);
	}
	else
	{
		if (args <= 9)
			ft_putchar(args + '0');
		else
		{
			if (type == 'x')
				ft_putchar((args - 10) + 'a');
			else if (type == 'X')
				ft_putchar((args - 10) + 'A');
		}
		++*c;
	}
}
