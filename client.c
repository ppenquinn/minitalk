/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:54:51 by nappalav          #+#    #+#             */
/*   Updated: 2024/06/29 12:12:59 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	handle_error(int code)
{
	if (code == 1)
		ft_printf("Argument Error\n");
	else if (code == 2)
		ft_printf("PID Error\n");
	return (0);
}

static void ft_send_bit(int pid, char c)
{
	int bit;

	bit = 7;
	while (bit != -1)
	{
		if (c >> bit-- & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (handle_error(1));
	if (!ft_atoi_check(argv[1], &pid))
		return (handle_error(2));
	i = 0;
	while (argv[2][i] != 0)
	{
		ft_send_bit(pid, argv[2][i]);
		i++;
	}
	ft_send_bit(pid,'\n');
	return (0);
}
