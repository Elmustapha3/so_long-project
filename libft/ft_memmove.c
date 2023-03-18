/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:33:04 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/29 08:48:14 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sr;
	char	*ds;

	sr = (char *)src;
	ds = (char *)dst;
	if (sr < ds)
	{
		while (len--)
			ds[len] = sr[len];
	}
	else
		ft_memcpy(ds, sr, len);
	return (dst);
}
