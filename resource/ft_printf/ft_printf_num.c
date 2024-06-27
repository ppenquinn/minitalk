/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 06:33:30 by nappalav          #+#    #+#             */
/*   Updated: 2023/11/29 22:20:28 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pos(unsigned int nbr, char *base, unsigned int div)
{
	char	ans;

	if (nbr >= div)
	{
		if (ft_printf_pos(nbr / div, base, div) == -1)
			return (-1);
		nbr %= div;
	}
	ans = base[nbr];
	if (write(1, &ans, 1) == -1)
		return (-1);
	return (0);
}

static int	ft_printf_nbr(int nbr)
{
	char	ans;

	if (nbr < 0 && nbr > -10)
		if (write(1, "-", 1) == -1)
			return (-1);
	if (nbr >= 10 || nbr <= -10)
	{
		if (ft_printf_nbr(nbr / 10) == -1)
			return (-1);
		nbr %= 10;
	}
	if (nbr >= 0)
		ans = '0' + nbr;
	else
		ans = '0' - nbr;
	if (write(1, &ans, 1) == -1)
		return (-1);
	return (0);
}

int	ft_printf_u(unsigned int nbr, char *base)
{
	unsigned int	div;
	unsigned int	temp;
	int				length;

	length = 0;
	temp = nbr;
	div = ft_strlen(base);
	if (temp == 0)
		length++;
	while (temp > 0)
	{
		temp /= div;
		length++;
	}
	if (ft_printf_pos(nbr, base, div) == -1)
		return (-1);
	return (length);
}

int	ft_printf_d(int nbr)
{
	int	temp;
	int	length;

	length = 0;
	temp = nbr;
	if (temp <= 0)
	{
		if (temp == INT_MIN)
			temp = INT_MAX;
		else
			temp *= -1;
		length++;
	}
	while (temp > 0)
	{
		temp /= 10;
		length++;
	}
	if (ft_printf_nbr(nbr) == -1)
		return (-1);
	return (length);
}
