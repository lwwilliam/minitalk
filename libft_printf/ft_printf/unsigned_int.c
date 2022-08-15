/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:06:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/06/22 15:31:33 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_int(unsigned int n, int *c)
{
	if (n >= 10)
	{
		unsigned_int((n / 10), c);
		unsigned_int((n % 10), c);
	}
	else
	{
		ft_putchar(n + 48);
		++*c;
	}
}
