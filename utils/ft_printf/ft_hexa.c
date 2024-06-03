/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:38:39 by nosman            #+#    #+#             */
/*   Updated: 2024/05/09 16:38:41 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lilx(unsigned int num)
{
	int		len;
	char	*s;

	len = 0;
	s = "0123456789abcdef";
	if (num > 15)
		len += ft_lilx(num / 16);
	len += ft_putchar(s[num % 16]);
	return (len);
}

int	ft_bigx(unsigned int num)
{
	int		len;
	char	*s;

	len = 0;
	s = "0123456789ABCDEF";
	if (num > 15)
		len += ft_bigx(num / 16);
	len += ft_putchar(s[num % 16]);
	return (len);
}
