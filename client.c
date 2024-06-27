/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:54:51 by nappalav          #+#    #+#             */
/*   Updated: 2024/06/27 18:39:20 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	handle_error(int code)
{
	if (code == 1)
		ft_printf("Argument Error");
	else if (code == 2)
		ft_printf("PID Error");
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (handle_error(1));
	if (!ft_atoi_check(argv[1], &pid))
		return (handle_error(2));
}
