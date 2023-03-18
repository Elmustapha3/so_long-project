/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:41:28 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/30 10:37:27 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srcc;

	i = 0;
	dest = (char *)dst;
	srcc = (char *)src;
	if (dest == srcc)
		return (dest);
	if (!dest && !srcc)
		return (NULL);
	while (i < n)
	{
		dest[i] = srcc[i];
		i++;
	}
	return (dest);
}
// int	main(void)
// {
// 	// char dst[] = "NULL";
// 	char *p = "yt";
// 	char *c = "yt";
// 	// char src[] = "NUL";
// 	printf("%s\n", memcpy(p , c, 6));
// }
