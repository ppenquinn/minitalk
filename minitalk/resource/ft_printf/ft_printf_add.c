/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:16:09 by nappalav          #+#    #+#             */
/*   Updated: 2023/11/29 22:20:21 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_lpos(unsigned long nbr, char *base, unsigned int div)
{
	char	ans;

	if (nbr >= div)
	{
		if (ft_printf_lpos(nbr / div, base, div) == -1)
			return (-1);
		nbr %= div;
	}
	ans = base[nbr];
	if (write(1, &ans, 1) == -1)
		return (-1);
	return (0);
}

int	ft_printf_p(unsigned long nbr, char *base)
{
	unsigned long	div;
	unsigned long	temp;
	int				length;

	length = 0;
	temp = nbr;
	div = ft_strlen(base);
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (temp == 0)
		length++;
	while (temp > 0)
	{
		temp /= div;
		length++;
	}
	if (ft_printf_lpos(nbr, base, div) == -1)
		return (-1);
	return (2 + length);
}
