/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:33:00 by lwilliam          #+#    #+#             */
/*   Updated: 2022/06/23 13:03:33 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *type, ...);
int		ft_putchar(char x);
void	ft_putnbr(int n, int *c);
int		ft_putstr(char *s);
void	ptr_address(unsigned long args, int *c);
void	unsigned_int(unsigned int n, int *c);
void	bx_or_sx(unsigned int args, char type, int *c);

#endif