/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:48:29 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/23 14:16:03 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	last_byte(int sig, int byte, char *tmp)
{
	int		x;
	int		bit_count;
	char	last_char;

	x = ft_strlen(tmp);
	last_char = '\0';
	if (byte == x)
	{
		bit_count = 7;
		while (bit_count >= 0)
		{
			if ((last_char >> bit_count--) & 1)
				kill(sig, SIGUSR1);
			else
				kill(sig, SIGUSR2);
			usleep(50);
		}
	}
}

void	end_test(int sig)
{
	(void)sig;
	ft_printf("Message received by server.\n");
	exit (0);
}

void	sig_reply(int sig, char *tmp)
{
	int		bit_count;
	int		byte;

	byte = 0;
	while (tmp[byte])
	{
		bit_count = 7;
		while (bit_count >= 0)
		{
			usleep(50);
			if ((tmp[byte] >> bit_count--) & 1)
			{
				kill(sig, SIGUSR1);
				usleep(50);
			}
			else
			{
				kill(sig, SIGUSR2);
				usleep(50);
			}
			usleep(50);
		}
		byte++;
		last_byte(sig, byte, tmp);
	}
}

int	main(int ac, char *av[])
{
	int	x;

	signal(SIGUSR2, end_test);
	if (ac != 3)
	{
		ft_printf("Error! Format ->> (./client <PID> <message>)\n");
		exit (0);
	}
	x = atoi(av[1]);
	if (av[2])
		sig_reply(x, av[2]);
}
