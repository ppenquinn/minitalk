/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:30:27 by nappalav          #+#    #+#             */
/*   Updated: 2024/06/29 12:15:44 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	bit = 7;

	(void)context;
	(void)info;

	c += (signum == SIGUSR1) << bit--;
	if (bit == -1)
	{
		ft_printf("%c", c);
		bit = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: [%d]\n", getpid());
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		usleep(300);
	}
	return (0);
}
