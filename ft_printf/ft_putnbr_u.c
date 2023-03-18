/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:22:20 by eej-jama          #+#    #+#             */
/*   Updated: 2022/11/05 15:54:47 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	unsigned long	a;
	int static		len;

	len = 0;
	a = (unsigned long)n;
	if (a > 9)
	{
		ft_putnbr_u(a / 10);
		a %= 10;
	}
	if (a < 10)
	{
		ft_putchar(a + 48);
		len++;
	}
	return (len);
}
