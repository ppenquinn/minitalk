/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:43:38 by nappalav          #+#    #+#             */
/*   Updated: 2024/04/19 13:18:22 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_printf_c(int c);
int		ft_printf_s(char *str);
int		ft_printf_u(unsigned int nbr, char *base);
int		ft_printf_d(int nbr);
int		ft_printf_p(unsigned long nbr, char *base);

#endif
