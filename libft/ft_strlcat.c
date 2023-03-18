/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:34:40 by eej-jama          #+#    #+#             */
/*   Updated: 2022/10/29 14:41:45 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ls;
	size_t	ld;
	size_t	i;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dstsize <= ld)
		return (dstsize + ls);
	while (src[i] && i < dstsize - ld - 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ls + ld);
}
// int main()
// {
// 	char dst[20] = "mohsammmed";
// 	char src[] = "NULL";
// 	printf("%zu",ft_strlcat(dst,src,12));
// 	printf("%s",dst);
// 	return 0;
// }
