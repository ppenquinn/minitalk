/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:20:04 by nappalav          #+#    #+#             */
/*   Updated: 2023/11/29 22:20:08 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pick_mode(char mode, va_list *arg)
{
	int	cnt;

	cnt = 0;
	if (mode == 'c')
		cnt = ft_printf_c(va_arg(*arg, int));
	else if (mode == 's')
		cnt = ft_printf_s(va_arg(*arg, char *));
	else if (mode == 'd' || mode == 'i')
		cnt = ft_printf_d(va_arg(*arg, int));
	else if (mode == 'X')
		cnt = ft_printf_u(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (mode == 'x')
		cnt = ft_printf_u(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (mode == 'u')
		cnt = ft_printf_u(va_arg(*arg, unsigned int), "0123456789");
	else if (mode == 'p')
		cnt = ft_printf_p(va_arg(*arg, unsigned long), "0123456789abcdef");
	else if (mode == '%')
		cnt = ft_printf_c('%');
	else
		cnt = ft_printf_c(mode);
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		cnt;
	int		temp;

	i = 0;
	cnt = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			temp = pick_mode(str[++i], &arg);
		else
			temp = ft_printf_c(str[i]);
		if (temp == -1)
			return (-1);
		cnt += temp;
		i++;
	}
	va_end(arg);
	return (cnt);
}
