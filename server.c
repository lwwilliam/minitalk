/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:49:24 by lwilliam          #+#    #+#             */
/*   Updated: 2022/08/22 16:37:15 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	usr1_handle(int sig, siginfo_t *info, void *context)
{
	static int	tmp = 0;
	static int	count = 0;

	(void)context;
	if (sig == SIGUSR1)
		tmp |= 1;
	if (++count == 8)
	{
		if (tmp == 0)
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &tmp, 1);
		count = 0;
		tmp = 0;
	}
	else
		tmp <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = usr1_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause ();
}
