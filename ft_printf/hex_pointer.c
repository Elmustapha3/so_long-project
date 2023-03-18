/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:46:26 by eej-jama          #+#    #+#             */
/*   Updated: 2022/11/05 15:55:51 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_pointer(size_t a)
{
	int	len;

	len = 0;
	if (a > 15)
	{
		len += hex_pointer(a / 16);
		a %= 16;
	}
	if (a < 16)
	{
		if (a >= 10)
			ft_putchar(a + 87);
		else
			ft_putchar(a + 48);
		len++;
	}
	return (len);
}
